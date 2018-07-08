#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

class Solution {
public:
    int find_median(vector<int>& nums){
        sort(nums.begin(), nums.end());
        int size = nums.size();
        if (size % 2 == 0){
            return (nums[size/2] + nums[size/2 - 1]) / 2;
        } else {
            return nums[size/2];
        }
    }
    
    int minMoves2(vector<int>& nums) {
        int median = find_median(nums);

        int num = 0;
        int size = nums.size();
        
        for (int i = 0; i != size; ++i){
            num += abs(median - nums[i]);
        }

        return num;        
    }
};

int main(){
    Solution solution;
    
    vector<int> array = {1, 2, 3};
    vector<int> array2 = {1, 4, 7, 8};

    cout << solution.minMoves2(array) << endl;
    cout << solution.minMoves2(array2) << endl;
    return 0;
}