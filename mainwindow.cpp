#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QPainter"
#include "QGraphicsView"
#include "QMessageBox"
#include "QDoubleValidator"
#include "QRect"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->heightInput1->setValidator(new QDoubleValidator(1, 300, 2, this));
    ui->heightInput2->setValidator(new QDoubleValidator(1, 300, 2, this));
    ui->widthInput1->setValidator(new QDoubleValidator(1, 300, 2, this));
    ui->widthInput2->setValidator(new QDoubleValidator(1, 300, 2, this));

    ui->heightInput1->setText(QString::number(firstRec.getHeight()));
    ui->heightInput2->setText(QString::number(secondRec.getHeight()));
    ui->widthInput1->setText(QString::number(firstRec.getWidth()));
    ui->widthInput2->setText(QString::number(secondRec.getWidth()));

    this->firstRec.setPoint(qMakePair(15, 60));
    this->secondRec.setPoint(qMakePair(500, 60));

    setQRect(this->firstRec, this->qr1);
    setQRect(this->secondRec, this->qr2);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event) {
    QPainter painter(this);

    painter.drawRect(this->qr1);
    painter.drawRect(this->qr2);

    if (this->qrBig.height()) {
        painter.setPen(Qt::green);
        painter.drawRect(this->qrBig);
    }

    if (this->qrIntersected.height()) {
        painter.setPen(Qt::red);
        painter.setBrush(Qt::cyan);
        painter.drawRect(this->qrIntersected);
    }
}

void MainWindow::on_up1_clicked()
{
    this->firstRec.moveY(-15);
    setQRect(this->firstRec, this->qr1);

    this->update();
}

void MainWindow::on_left1_clicked()
{
    this->firstRec.moveX(-15);
    setQRect(this->firstRec, this->qr1);

    this->update();
}

void MainWindow::on_down1_clicked()
{
    this->firstRec.moveY(15);
    setQRect(this->firstRec, this->qr1);

    this->update();
}

void MainWindow::on_right1_clicked()
{
    this->firstRec.moveX(15);
    setQRect(this->firstRec, this->qr1);

    this->update();
}


void MainWindow::on_up2_clicked()
{
    this->secondRec.moveY(-15);
    setQRect(this->secondRec, this->qr2);

    this->update();
}

void MainWindow::on_left2_clicked()
{
    this->secondRec.moveX(-15);
    setQRect(this->secondRec, this->qr2);

    this->update();
}

void MainWindow::on_down2_clicked()
{
    this->secondRec.moveY(15);
    setQRect(this->secondRec, this->qr2);

    this->update();
}

void MainWindow::on_right2_clicked()
{
    this->secondRec.moveX(15);
    setQRect(this->secondRec, this->qr2);

    this->update();
}

void MainWindow::on_setSize1_clicked()
{
    double h = ui->heightInput1->text().toDouble();
    double w = ui->widthInput1->text().toDouble();

    if (h < 1 || w < 1) {
        QMessageBox::warning(this, "", "Некоректне введення даних");
        return;
    }

    this->firstRec.setHeight(h);
    this->firstRec.setWidth(w);

    setQRect(this->firstRec, this->qr1);
    this->update();
}

void MainWindow::on_setSize2_clicked()
{
    double h = ui->heightInput2->text().toDouble();
    double w = ui->widthInput2->text().toDouble();

    if (h < 1 || w < 1) {
        QMessageBox::warning(this, "", "Некоректне введення даних");
        return;
    }

    this->secondRec.setHeight(h);
    this->secondRec.setWidth(w);

    setQRect(this->secondRec, this->qr2);
    this->update();
}

void MainWindow::on_getSquareButton1_clicked()
{
    QMessageBox::information(this, "", QString::number(this->firstRec.square()), QMessageBox::Ok);
}

void MainWindow::on_getSquareButton2_clicked()
{
    QMessageBox::information(this, "", QString::number(this->secondRec.square()), QMessageBox::Ok);
}

void MainWindow::on_findSmallestRectContainer_clicked()
{
    Rectangle rect = Rectangle::smallestRectThanContainsTwoRects(this->firstRec, this->secondRec);

    setQRect(rect, this->qrBig);
    this->update();

    QString info = rect.getShortInfo();

    QMessageBox::information(this, "", info, QMessageBox::Ok);
}

void MainWindow::on_findIntersection_clicked()
{
    // this->qrIntersected = this->qr1.intersected(this->qr2);

    Rectangle intersected = Rectangle::rectsIntersection(this->firstRec, this->secondRec);

    if (intersected.getWidth()) {
        setQRect(intersected, this->qrIntersected);
        QString info = intersected.getShortInfo();

        QMessageBox::information(this, "", info, QMessageBox::Ok);

    } else {
        QMessageBox::information(this, "", "Чотирикутники не перетинаються", QMessageBox::Ok);
    }

    this->update();
}
