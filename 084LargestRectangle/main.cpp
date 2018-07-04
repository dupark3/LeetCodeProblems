#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    template <class T>
    int localMax(T begin, T end){
        
    }

    int largestRectangleArea(vector<int>& heights) {
        int max_width = heights.size();
        int max_area = 0;
        for (int i = max_width; i != 0; --i){
            for (int j = 0; j != max_width - i + 1; ++j){
                max_area = max(max_area, i * localMax(heights.begin() + j, heights.begin() + i));
            }
        }
        return max_area;
    }
};

int main(){
    Solution solution;
    vector<int> input = {2,1,5,6,2,3};
    solution.largestRectangleArea(input);
    return 0;
}