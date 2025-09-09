#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
class ManhattanDistance;
struct Point {
    int x, y;
    Point(int x, int y) : x(x), y(y) {}
};
class ManhattanDistance {
    private:
    std::vector<Point> points;
    std::vector<int> sums;
    std::vector<int> diffs;
    for (int i = 0; i < points.size(); ++i) {
        sums.push_back(points[i].x + points[i].y);
        diffs.push_back(points[i].x - points[i].y);
    }
    int minSum = *std::min_element(sums.begin(), sums.end());
    int maxSum = *std::max_element(sums.begin(), sums.end());
    int mindiff= *std::min_element(sums.begin(), sums.end())
    int maxdiff = *std::max_element(sums.begin(), sums.end());
    int maxDistance() {
        return std::max(maxSum - minSum, maxdiff - mindiff);
    }