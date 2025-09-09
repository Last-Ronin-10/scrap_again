#include<iostream>
#include <vector>
int main(){
    int n1,m1,n2,m2,n3,m3;
    std::cin>>n1;
    std::cin>>n2;
    std::cin>>n3;
    std::cin>>m1;
    std::cin>>m2;
    std::cin>>m3;
    int s1;
    int s2;
    int s3;
    s1=(m2-m1)/(n2-n1);
    s2=(m3-m2)/(n3-n2);
    s3=(m3-m1)/(n3-n1);
    if (s1==s2==s3){
        std::cout<<"Lines are collinear"<<std::endl;
    }
    else{
    std::cout<<"Lines are not collinear"<<std::endl;
    }
    return 0;
} 