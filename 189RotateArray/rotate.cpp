#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        k = k % size;
        
        // reverse last k elements
        reverse(nums.begin() + (size - k), nums.end());

        // reverse first size - k elements
        reverse(nums.begin(), nums.begin() + (size - k));

        // reverse whole thing
        reverse(nums.begin(), nums.end());
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1,2,3,4,5,6}; // 6 2 3 4 5 1
    for (int i = 0; i != nums.size(); ++i){
        cout << nums[i] << " ";
    }
    cout << endl;

    solution.rotate(nums, 4);
    for (int i = 0; i != nums.size(); ++i){
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}