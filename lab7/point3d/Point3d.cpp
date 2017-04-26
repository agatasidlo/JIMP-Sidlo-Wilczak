#include <iostream>
#include <cmath>
#include "Point3d.h"

using ::std::pow;
using ::std::sqrt;

namespace datastructures {
    Point3d::Point3d() {
        SetX(0);
        SetY(0);
        SetZ(0);
        std::cout << "Konstruktor bezparametrowy Point3d" << std::endl;
    }

    Point3d::Point3d(double x, double y, double z) {
        SetX(x);
        SetY(y);
        z_ = z;
        std::cout << "Konstruktor parametrowy Point3d" << std::endl;
    }

    Point3d::~Point3d() {
        std::cout << "Destruktor Point3d" << std::endl;
    }

    double Point3d::distance(const Point3d &other) {
        return sqrt(pow(GetX() - other.GetX(), 2) + pow(GetY() - other.GetY(), 2) + pow(GetZ() - other.GetZ(), 2));
    }

    double Point3d::GetZ() const {
        return z_;
    }

    void Point3d::SetZ(double z) {
        z_ = z;
    }
}