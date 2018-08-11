#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>


using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // fastest to build a hash map... but O(n) space and O(n) time

        // sort it, then O(1) space but O(nlogn) time
        sort(nums.begin(), nums.end());

        auto it = upper_bound(nums.begin(), nums.end(), 0);
        if (it == nums.end()){
            return 1;
        } else {
            int j = 1;
            while (*it == j){
                while(*it == *(it + 1)){
                    ++it;
                }
                ++j;
                ++it;
            }
            return j;
        }

        return 1;
    }
};


int main(){
    Solution solution;
    vector<int> nums = {1, 1, 3, 3, 2, 3, 5, 6, 7, 8, 9, 10, 12, 13};
    cout << solution.firstMissingPositive(nums) << endl;

    return 0;
}