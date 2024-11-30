#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>

struct Point {
    int x, y;
    
    Point(int x = 0, int y = 0) : x(x), y(y) {}
    
    double norm(const Point& other) const {
        return std::sqrt(std::pow(x - other.x, 2) + std::pow(y - other.y, 2));
    }
};

struct Segment {
    Point p1, p2;
    double length;
    
    Segment(Point p1, Point p2) : p1(p1), p2(p2), length(p1.norm(p2)) {}
    
    bool operator<(const Segment& other) const {
        return length < other.length;
    }
};

int main() {
    std::ifstream inputFile("input.txt");
    std::ofstream outputFile("output.txt");
    
    if (!inputFile || !outputFile) {
        std::cerr << "Error opening file." << std::endl;
        return 1;
    }

    std::vector<Point> points;
    char ch;
    int x, y;
    
    while (inputFile >> ch >> x >> ch >> y >> ch) {
        points.push_back(Point(x, y));
    }

    std::vector<Segment> segments;
    
    for (size_t i = 0; i < points.size(); ++i) {
        for (size_t j = i + 1; j < points.size(); ++j) {
            segments.push_back(Segment(points[i], points[j]));
        }
    }

    std::sort(segments.begin(), segments.end());

    for (const auto& segment : segments) {
        outputFile << "(" << segment.p1.x << ", " << segment.p1.y << ") "
                   << "(" << segment.p2.x << ", " << segment.p2.y << ")\n";
    }

    std::cout << "Successfully written to: 'output.txt'." << std::endl;
}
