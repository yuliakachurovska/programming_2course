#include <iostream>
#include <cmath>
using namespace std;

class Point {
protected:
    double x, y;
    int dimension;  //2D

public:
    Point() : x(0), y(0), dimension(2) {}

    Point(double x, double y) : x(x), y(y), dimension(2) {}

    virtual void input() {
        cout << "Enter coordinates x and y: ";
        cin >> x >> y;
    }

    virtual void output() const {
        cout << "Point: (" << x << ", " << y << ")";
    }

    double distanceTo(const Point& other) const {
        return sqrt(pow(x - other.x, 2) + pow(y - other.y, 2));
    }

    int getDimension() const { return dimension; }
};

class Point3D : public Point {
private:
    double z;

public:
    Point3D() : Point(), z(0) {
        dimension = 3;  //3D
    }

    Point3D(double x, double y, double z) : Point(x, y), z(z) {
        dimension = 3;
    }

    void input() override {
        cout << "Enter coordinates x, y and z: ";
        cin >> x >> y >> z;
    }

    void output() const override {
        cout << "Point: (" << x << ", " << y << ", " << z << ")";
    }

    double distanceTo(const Point3D& other) const {
        return sqrt(pow(x - other.x, 2) + pow(y - other.y, 2) + pow(z - other.z, 2));
    }
};

class LineSegment {
private:
    Point* point1;
    Point* point2;

public:
    LineSegment(Point* point1, Point* point2) : point1(point1), point2(point2) {}

    void output() const {
        cout << "Line segment ";
        point1->output();
        cout << " and ";
        point2->output();
        cout << endl;
    }

    double length() const {
        if (point1->getDimension() == 2 && point2->getDimension() == 2) {
            return point1->distanceTo(*point2);
        } else if (point1->getDimension() == 3 && point2->getDimension() == 3) {
            const Point3D* p1 = (const Point3D*)point1;
            const Point3D* p2 = (const Point3D*)point2;
            return p1->distanceTo(*p2);
        }
        cout << "Error" << endl;
        return 0;
    }
};

int main() {
    Point p1(7, 0), p2(4, -4);
    Point3D p3(3, -5, 7), p4(-8, 1, 4);

    LineSegment s1(&p1, &p2);
    LineSegment s2(&p3, &p4);

    s1.output();
    cout << "Length: " << s1.length() << endl;
    s2.output();
    cout << "Length: " << s2.length() << endl;
}
