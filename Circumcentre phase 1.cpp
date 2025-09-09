#include <iostream>
#include <cmath>
using namespace std;
pair<double, double> midpoint(double x1, double y1, double x2, double y2) {
    return {(x1 + x2) / 2.0, (y1 + y2) / 2.0};
}
double perpendicularSlope(double x1, double y1, double x2, double y2) {
    double dx = x2 - x1;
    double dy = y2 - y1;
    if (dy == 0) return INFINITY; // horizontal line → vertical bisector
    if (dx == 0) return 0;        // vertical line → horizontal bisector
    return -dx / dy;
}
pair<double, double> intersection(double m1, pair<double, double> p1,
                                  double m2, pair<double, double> p2) {
    double x, y;
    if (isinf(m1)) {
        x = p1.first;
        y = m2 * (x - p2.first) + p2.second;
    } else if (isinf(m2)) {
        x = p2.first;
        y = m1 * (x - p1.first) + p1.second;
    } else {
        x = (m1 * p1.first - m2 * p2.first + p2.second - p1.second) / (m1 - m2);
        y = m1 * (x - p1.first) + p1.second;
    }
    return {x, y};
}
double distance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}
int main() {
    double Ax = 6, Ay = 0;
    double Bx = 0, By = 0;
    double Cx = 0, Cy = 8;
    auto midAB = midpoint(Ax, Ay, Bx, By);
    auto midBC = midpoint(Bx, By, Cx, Cy);
    double slopeAB = perpendicularSlope(Ax, Ay, Bx, By);
    double slopeBC = perpendicularSlope(Bx, By, Cx, Cy);
    auto tower = intersection(slopeAB, midAB, slopeBC, midBC);
    double radius = distance(tower.first, tower.second, Ax, Ay);
    cout << "Tower should be placed at: (" << tower.first << ", " << tower.second << ")\n";
    cout << "Radius of coverage circle: " << radius << " km\n";
    if (radius <= 6.0)
        cout << "Setup is feasible.\n";
    else
        cout << "Radius exceeds 6 km. Setup not feasible.\n";
    return 0;
}