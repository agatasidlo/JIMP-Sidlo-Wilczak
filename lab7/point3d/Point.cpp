#include <cmath>
#include <iostream>
#include "Point.h"

using ::std::ostream;
using ::std::endl;
using ::std::pow;
using ::std::sqrt;
using ::std::ostream;
using ::std::ws;

Point::Point() : x_(0), y_(0) {
    std::cout << "Konstruktor bezparametrowy Point" << endl;
}

Point::Point(double x, double y) {
    std::cout << "Konstruktor parametrowy Point" << endl;
    x_ = x;
    y_ = y;
}

Point::~Point() {
    std::cout << "Destruktor Point" << std::endl;
}

double Point::distance(const Point &other) const {
    return sqrt(pow(GetX() - other.GetX(), 2) + pow(GetY() - other.GetY(), 2));
}

void Point::ToString(ostream *out) const {
    (*out) << "(" << GetX() << ";" << GetY() << ")";
}

double Point::GetX() const {
    return x_;
}

double Point::GetY() const {
    return y_;
}

void Point::SetX(double x) {
    x_ = x;
}

void Point::SetY(double y) {
    y_ = y;
}

ostream &operator<<(ostream &output, Point &p) {
    std::cout << "(" << p.GetX() << ", " << p.GetY() << ")" << std::endl;
    return output;
}