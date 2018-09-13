#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty())
            return -1;

        
        int pivot = findPivot(nums, 0, nums.size());
        // in order to get O(logn) time complexity,
        // array must be sorted of sorts... 
    }

    int findPivot(const vector<int>& nums, int left, int right){
        while(true){
            int mid = left + (right - left) / 2;
            if (mid != 0 && nums[mid] < nums[mid - 1]){
                return mid;
            } else if (nums[0] < nums[mid]){
                // go right
                return findPivot(nums, mid + 1, right);
            } else {
                // go left
                return findPivot(nums, left, mid);
            }
        }
    }
};

int main(){
    Solution solution;
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    cout << solution.search(nums, 1) << endl; // 5
    cout << solution.search(nums, 3) << endl; // -1

    return 0;
}