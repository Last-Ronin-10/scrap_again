#include <iostream>
#include <vector>

int main(){
    int x1,y1,x2,y2,x3,y3;
    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    int ar;
    ar = (x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2));
    if (ar==0){
        std::cout<<"The points are collinear"<<std::endl;
    } else {   
        std::cout<<"The points are not collinear"<<std::endl;
    }