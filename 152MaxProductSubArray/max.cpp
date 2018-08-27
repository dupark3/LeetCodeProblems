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
        
        int posMax[nums.size()];
        int negMax[nums.size()];
        int result = nums[0];
        posMax[0] = nums[0];
        negMax[0] = nums[0];

        // find the number of negatives
        for (int i = 1; i != nums.size(); ++i){
            posMax[i] = max(nums[i], max(posMax[i-1] * nums[i], negMax[i-1]*nums[i]));
            negMax[i] = min(nums[i], min(posMax[i-1] * nums[i], negMax[i-1]*nums[i]));
            result = max(result, max(posMax[i], negMax[i]));
        }

        return result;
    }

};

int main(){
    Solution solution;

    vector<int> nums = {1, 2, -3, 3, 5, -2, -2};
    cout << solution.maxProduct(nums) << endl;

    return 0;
}