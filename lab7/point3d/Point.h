#ifndef PROJECTNAME_PATH_POINT_H_
#define PROJECTNAME_PATH_POINT_H_

class Point {
public:
    Point();

    Point(double x, double y);

    ~Point();

    void ToString(std::ostream *out) const;

    double distance(const Point &other) const;

    double GetX() const;

    double GetY() const;

    void SetX(double x);

    void SetY(double y);

private:
    double x_, y_;
};

std::ostream &operator<<(std::ostream &output, Point &p);

#endif  // PROJECTNAME_PATH_POINT_H_