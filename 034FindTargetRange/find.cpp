#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        // binary search fails = return {-1, -1}
        int left = 0;
        int right = nums.size();

        // binary search for first occurance of target
        int first = firstBinarySearch(left, right, nums, target);

        // binary search for last occurance of target
        // int last = lastBinarySearch(left, right, nums, target);
        // return {first, last};
        return {first, first};
    }

    int firstBinarySearch(int left, int right, const vector<int>& nums, int target){
        while(true){
            int mid = left + (right - left) / 2;
            if (nums[mid] < target){
                // going right
                if (mid == nums.size() -1){
                    return -1;
                }
                left = mid + 1;
            } else {
                // going left or found target
                if (mid == 0 && nums[mid] != target){
                    return -1;
                } else if( mid == 0 || (nums[mid] == target && nums[mid - 1] != target)){
                    return mid;
                } else {
                    right = mid;
                }
            }
        }
    }

    int lastBinarySearch(int left, int right, const vector<int>& nums, int target){
        
    }
};

int main(){
    Solution solution;
    vector<int> nums = {5, 6, 8, 8, 8, 9, 9, 10};
    vector<int> range = solution.searchRange(nums, 8);
    cout << range[0] << ", " << range[1] << endl; // 2, 4
}