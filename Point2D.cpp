#include "Point2D.h"

Point2D::Point2D(double x=0, double y=0){
    this->x = x;
    this->y = y;
}

static double Point2D::distance(const Point2D &a, const Point2D &b){
    return sqrt(pow(a.x-b.x, 2) + pow(a.y-b.y, 2));
}

bool Point2D::operator==(const Point2D &a, const Point2D &b){
    return a.x==b.x && a.y==b.y;
}

bool Point2D::operator!=(const Point2D &a, const Point2D &b){
    return a.x!=b.x && a.y!=b.y;
}

std::ostream& Point2D::operator<<(std::ostream &out, const Point2D &p){
    out << "(" << p.x << ", " << p.y << ")";
    return out;
}
