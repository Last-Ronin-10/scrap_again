#include <iostream>
#include <algorithm>
#include <cmath>
#include <numeric>

bool collinear(int x1, int y1, int x2, int y2, int x3, int y3) {
    return (y2 - y1) * (x3 - x2) == (y3 - y2) * (x2 - x1);
}

int main() {
    int x1, x2, x3, y1, y2, y3;
    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    if (collinear(x1, y1, x2, y2, x3, y3)) {
        std::cout << "Lines are Collinear so Zero integral points are there" << std::endl;
    } else {
        int area = std::abs((x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2)) / 2);
        int boundary_points = std::gcd(std::abs(x2 - x1), std::abs(y2 - y1)) +
                              std::gcd(std::abs(x3 - x2), std::abs(y3 - y2)) +
                              std::gcd(std::abs(x1 - x3), std::abs(y1 - y3));
        int interior_points = area - (boundary_points / 2) + 1;

        std::cout << "Number of integral points inside the triangle are: " << interior_points << std::endl;
    }
}