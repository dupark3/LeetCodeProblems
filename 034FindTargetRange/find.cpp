#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        // if target does not exist, return -1
        if (!binary_search(nums.begin(), nums.end(), target)){
            return {-1, -1};
        }
        
        int first = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int last = upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;
        
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