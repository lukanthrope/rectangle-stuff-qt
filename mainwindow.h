#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QRect"
#include "rectangle.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    Rectangle firstRec = Rectangle(200, 80);
    Rectangle secondRec = Rectangle(90, 80);

    QRect qr1;
    QRect qr2;
    QRect qrBig;
    QRect qrIntersected;

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    virtual void paintEvent(QPaintEvent *event);

    static void setQRect(Rectangle &r, QRect &qr) {
        qr = QRect(r.getPoint().first, r.getPoint().second, r.getWidth(), r.getHeight());
    }

private slots:
    void on_up1_clicked();

    void on_left1_clicked();

    void on_down1_clicked();

    void on_right1_clicked();

    void on_up2_clicked();

    void on_left2_clicked();

    void on_down2_clicked();

    void on_right2_clicked();

    void on_setSize1_clicked();

    void on_setSize2_clicked();

    void on_getSquareButton1_clicked();

    void on_getSquareButton2_clicked();

    void on_findSmallestRectContainer_clicked();

    void on_findIntersection_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
