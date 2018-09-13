#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        // iterator returned that points to the first element not less than target
        vector<int>::iterator lower = lower_bound(nums.begin(), nums.end(), target);
        if (lower == nums.end() || *lower != target){
            return {-1, -1};
        }
        // get index of lower iterator
        int first = lower - nums.begin();

        // find the index of the last element that matches target
        // upper_bound returns an iterator to the first element greater than target
        // subtract 1 from upper_bound - begin to get the right index
        int last = upper_bound(lower, nums.end(), target) - nums.begin() - 1;
        
        return {first, last};
    }

    /*int firstBinarySearch(int left, int right, const vector<int>& nums, int target){
        while(true){
            int mid = left + (right - left) / 2;
            if (right - left <= 1 && nums[mid] != target){
                return -1;
            }
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
        while(true){

            int mid = left + (right - left) / 2;
            if (right - left <= 1 && nums[mid] != target){
                return -1;
            }
            if (nums[mid] > target){
                // going left
                if (mid == 0){
                    return -1;
                }
                right = mid;
            } else {
                // going right or target found
                if (mid == nums.size() - 1 && nums[mid] != target){
                    return -1;
                } else if (mid == nums.size() - 1 || (nums[mid] == target && nums[mid + 1] != target)){
                    return mid;
                } else {
                    left = mid + 1;
                }
            }
        }
    }*/
};

int main(){
    Solution solution;
    vector<int> nums = {5, 6, 8, 8, 8, 9, 9, 11};
    vector<int> range = solution.searchRange(nums, 9);
    cout << range[0] << ", " << range[1] << endl; // 2, 4
}