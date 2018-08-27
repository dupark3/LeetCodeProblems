#include <algorithm>
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 0){
            return 0;
        } else if (nums.size() == 1){
            return nums[0];
        }
        
        int maximum = INT_MIN;
        for (int i = 0; i != nums.size(); ++i){
            maximum = max(maximum, products(nums, i));
        }

        return maximum;
    }

private:
    int products(vector<int>& nums, int start){
        int maximum = INT_MIN;
        for (int i = start; i != nums.size(); ++i){
            maximum = max(maximum, subarrayProduct(nums, start, i));
        }
        return maximum;
    }

    int subarrayProduct(vector<int>& nums, int start, int end){
        int product = nums[start];
        for (int i = start + 1; i <= end; ++i){
            product *= nums[i];
        }
        return product;
    }
};

int main(){
    Solution solution;

    vector<int> nums = {1, 2, 0, 3, 5, -2, -2};
    cout << solution.maxProduct(nums) << endl;

    return 0;
}