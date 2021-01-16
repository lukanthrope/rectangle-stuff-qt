#include "QPair"
#include "QDebug"

#ifndef RECTANGLE_H
#define RECTANGLE_H


class Rectangle
{
public:
    Rectangle(double width, double height);
    double getWidth();
    double getHeight();
    void setWidth(double width);
    void setHeight(double height);

    QPair<double, double> getPoint();
    void setPoint(QPair<double, double> point);

    void moveX(double x);
    void moveY(double Y);
    QString getShortInfo();

    double square();

    static Rectangle smallestRectThanContainsTwoRects(Rectangle r1, Rectangle r2) {
        QPair<double, double> r1Point1 = r1.getPoint();
        QPair<double, double> r2Point1 = r2.getPoint();
        std::vector<double> xs;

        xs.push_back(r1Point1.first + r1.getWidth());
        xs.push_back(r1Point1.first);
        xs.push_back(r2Point1.first);
        xs.push_back(r2Point1.first + r2.getWidth());

        std::vector<double> ys;

        ys.push_back(r1Point1.second);
        ys.push_back(r1Point1.second + r1.getHeight());
        ys.push_back(r2Point1.second);
        ys.push_back(r2Point1.second + r2.getHeight());

        QPair <double, double> maxPoint = qMakePair(*max_element(xs.begin(), xs.end()), *max_element(ys.begin(), ys.end()));
        QPair <double, double> minPoint = qMakePair(*min_element(xs.begin(), xs.end()), *min_element(ys.begin(), ys.end()));

        double width = maxPoint.first - minPoint.first;
        double height = maxPoint.second - minPoint.second;

        Rectangle rect = Rectangle(width, height);
        rect.setPoint(minPoint);

        return rect;
    }

    static Rectangle rectsIntersection(Rectangle r1, Rectangle r2) {
        double leftX = fmax(r1.getPoint().first, r2.getPoint().first);
        double rightX = fmin(r1.getPoint().first + r1.getWidth(), r2.getPoint().first + r2.getWidth());
        double topY = fmax(r1.getPoint().second, r2.getPoint().second);
        double bottomY = fmin(r1.getPoint().second + r1.getHeight(), r2.getPoint().second + r2.getHeight());

        Rectangle rect = Rectangle(0, 0);
        rect.setPoint(qMakePair(0, 0));

        if ( leftX < rightX && topY < bottomY ) {
            rect = Rectangle(rightX - leftX, bottomY - topY);
            rect.setPoint(qMakePair(leftX, topY));
        }

        return rect;
    }

private:
    double width, height;
    QPair<double, double> point = qMakePair(0, 0);
};

#endif // RECTANGLE_H
