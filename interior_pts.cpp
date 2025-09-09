#include <iostream>
#include <algorithm>
#include <cmath>
#include <numeric>
int main(){
    int x1, x2, x3, y1, y2, y3;
    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    int x4, y4;
    std::cin >> x4 >> y4;
    int area = std::abs((x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2)) / 2);
    int area1 = std::abs((x1*(y2 - y4) + x2*(y4 - y1) + x4*(y1 - y2)) / 2);
    int area2 = std::abs((x1*(y4 - y3) + x4*(y3 - y1) + x3*(y1 - y4)) / 2);
    int area3 = std::abs((x4*(y2 - y3) + x2*(y3 - y4) + x3*(y4 - y2)) / 2);
    if (area == area1 + area2 + area3){
        std::cout << "Point is inside the triangle" << std::endl;
    }
    return 0;
}