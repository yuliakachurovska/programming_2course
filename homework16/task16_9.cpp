#include <iostream>
#include <cmath>

class Figure3D {
public:
    virtual double volume() const = 0;
    virtual double surfaceArea() const = 0;
    virtual int vertices() const = 0;
    virtual ~Figure3D() {}
};

class Parallelepiped : public Figure3D {
private:
    double length;   // Довжина
    double width;    // Ширина
    double height;   // Висота

public:
    Parallelepiped(double l, double w, double h) {
        if (l <= 0 || w <= 0 || h <= 0) {
                throw std::invalid_argument("All dimensions must be positive values.");
            }
            length = l;
            width = w;
            height = h;
    }

    double volume() const override {
        return length * width * height;
    }

    double surfaceArea() const override {
        return 2 * (length * width + length * height + width * height);
    }

    double lateralSurfaceArea() const {
        return 2 * (length * height + width * height);
    }

    int vertices() const override {
        return 8; // Повертатимемо кількість вершин
    }
};

class Pyramid3 : public Figure3D {
private:
    double side;    // Довжина сторони рівностороннього трикутника
    double height;  // Висота піраміди

public:
    Pyramid3(double s, double h) {
        if (s <= 0 || h <= 0) {
                throw std::invalid_argument("All dimensions must be positive values.");
            }
            side = s;
            height = h;
    }

    double volume() const override {
        double baseArea = (std::sqrt(3) / 4) * side * side;  // Площа рівностороннього трикутника
        return (baseArea * height) / 3.0;
    }

    double surfaceArea() const override {
        double baseArea = (std::sqrt(3) / 4) * side * side;

        double slantHeight = std::sqrt((height * height) + (side / 2.0) * (side / 2.0));  // бічна сторона
        double lateralArea = 3 * (0.5 * side * slantHeight);  // 3 бічні грані

        return baseArea + lateralArea;
    }

    int vertices() const override {
        return 3 + 1;
    }
};

class Pyramid4 : public Figure3D {
private:
    double length;  // Довжина основи
    double width;   // Ширина основи
    double height;  // Висота піраміди

public:
    Pyramid4(double l, double w, double h) {
        if (l <= 0 || w <= 0 || h <= 0) {
                throw std::invalid_argument("All dimensions must be positive values.");
            }
            length = l;
            width = w;
            height = h;
    }

    double volume() const override {
        return (length * width * height) / 3.0;
    }

    double surfaceArea() const override {
        double baseArea = length * width;

        // Площа бічної поверхні
        // Площа двох трикутних граней з основою length
        double slantHeightLength = std::sqrt((height * height) + (length / 2.0) * (length / 2.0));
        double lateralAreaLength = length * slantHeightLength / 2.0;

        // Площа двох трикутних граней з основою width
        double slantHeightWidth = std::sqrt((height * height) + (width / 2.0) * (width / 2.0));
        double lateralAreaWidth = width * slantHeightWidth / 2.0;

        return baseArea + 2 * lateralAreaLength + 2 * lateralAreaWidth;
    }

    int vertices() const override {
        return 4 + 1;
    }
};

int main() {
    Figure3D* figures[] = {
        new Parallelepiped(2, 4, 4),
        new Parallelepiped(5, 5, 6),
        new Pyramid3(3, 7),
        new Pyramid3(2, 5),
        new Pyramid4(2, 3, 5),
        new Pyramid4(3, 4, 6),
    };

    double totalVolume = 0.0;
    double totalSurfaceArea = 0.0;
    int totalVertices = 0;

    for (Figure3D* figure : figures) {
        totalVolume += figure->volume();
        totalSurfaceArea += figure->surfaceArea();
        totalVertices += figure->vertices();
    }

    std::cout << "Volume: " << totalVolume << std::endl;
    std::cout << "Surface area: " << totalSurfaceArea << std::endl;
    std::cout << "Vertices: " << totalVertices << std::endl;

    for (Figure3D* figure : figures) {
        delete figure;
    }
}
