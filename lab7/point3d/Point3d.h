#ifndef JIMP_EXERCISES_PUNKT3D_H
#define JIMP_EXERCISES_PUNKT3D_H

#include "Point.h"

namespace datastructures {
    class Point3d : public Point {
    public:
        Point3d();

        Point3d(double x, double y, double z);

        ~Point3d();

        double distance(const Point3d &other);

        double GetZ() const;

        void SetZ(double z);

    private:
        double z_;
    };

}

#endif //JIMP_EXERCISES_PUNKT3D_H
