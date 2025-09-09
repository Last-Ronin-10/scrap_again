#include <bits/stdc++.h>
class Manhattan;
struct coordinates{
    int x;
    int y;
    coordinates(int x,int y) : x(x) , y(y){};
};
class Manhattan{
    public:
    std::vector<coordinates> cds;
    std::vector<int> sums;
    std::vector<int> diffs;
    void array_sum(std::vector<coordinates> cds){
        for(size_t i=0;i<cds.size();i++){
            sums.push_back(abs(cds[i].x+cds[i].y));
       }
    }
    void array_diff(std::vector<coordinates> cds){
        for (size_t i=0; i<cds.size();i++){
            diffs.push_back(abs(cds[i].x - cds[i].y));
        }
    }
    void sort_arrays(std::vector<int> sums,std::vector<int> diffs){
        for (size_t i=0;i<sums.size();i++){
            if (sums[i] < sums[i+1] {
                std::swap(sums[i], sums[i+1]);
            }
        }
        for (size_t i=0;i<diffs.size();i++){
            if (diffs[i] < diffs[i+1]) {
                std::swap(diffs[i], diffs[i+1]);
            }
        }
    }
    int manhattan_distance(std::vector<coordinates> cds){
        array_sum(cds);
        array_diff(cds);
        sort_arrays(sums, diffs);
        return sums[0] + diffs[0];
    }
}