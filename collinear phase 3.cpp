#include <iostream>
#include <vector>
class DistanceMethod;
struct Point{
    int x;
    int y;
    Point(int x, int y):x(x),y(y){}
};
class DistanceMethod{
public:
    std::vector<Point> points;
    DistanceMethod(std::vector<Point> points):points(points){}
    bool areCollinear(Point p1, Point p2, Point p3) {
        double d1 = std::sqrt((p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y));
        double d2 = std::sqrt((p3.x - p2.x) * (p3.x - p2.x) + (p3.y - p2.y) * (p3.y - p2.y));
        double d3 = std::sqrt((p3.x - p1.x) * (p3.x - p1.x) + (p3.y - p1.y) * (p3.y - p1.y));
        return (d1 + d2 == d3) || (d1 + d3 == d2) || (d2 + d3 == d1);
    }
};
int main(){
    std::vector<Point> points = {Point(1,1), Point(2,2), Point(3,3), Point(4,5)};
    DistanceMethod dm(points);
    for(size_t i=0; i<points.size(); i++){
        for(size_t j=i+1; j<points.size(); j++){
            for(size_t k=j+1; k<points.size(); k++){
                if(dm.areCollinear(points[i], points[j], points[k])){
                    std::cout << "Points (" << points[i].x << "," << points[i].y << "), ("
                              << points[j].x << "," << points[j].y << "), ("
                              << points[k].x << "," << points[k].y << ") are collinear." << std::endl;
                }
            }
        }
    }
    return 0;
}    