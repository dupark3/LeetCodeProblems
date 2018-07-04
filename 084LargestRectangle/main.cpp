#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    template <class T>
    int localMin(T begin, T end){
        int minimum = INT_MAX;
        while (begin != end){
            minimum = min(minimum, *begin);
            ++begin;
        }
        // cout << "   local min : " << minimum << endl;
        return minimum;
    }

    int largestRectangleArea(vector<int>& heights) {
        int max_width = heights.size();
        int max_area = 0;
        for (int i = max_width; i != 0; --i){
            // cout << "i : " << i << endl;
            for (int j = 0; j != max_width - i + 1; ++j){
                max_area = max(max_area, i * localMin(heights.begin() + j, heights.begin() + j + i));
                // cout << "   max_area = " << max_area << "   j = " << j << endl;
            }
        }
        return max_area;
    }
};

int main(){
    Solution solution;
    vector<int> input = {2,1,5,6,2,3};
    cout << solution.largestRectangleArea(input) << endl;
    return 0;
}