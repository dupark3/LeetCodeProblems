#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        vector<int> result;
        if (k > size){
            k = k % size;
        }
        for (int i = size - k; i != size; ++i){
            result.push_back(nums[i]);
        }
        for (int i = 0; i != size - k; ++i){
            result.push_back(nums[i]);
        }
        nums = result;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1,2,3,4,5,6,7};
    for (int i = 0; i != nums.size(); ++i){
        cout << nums[i] << " ";
    }
    cout << endl;

    solution.rotate(nums, 9);
    for (int i = 0; i != nums.size(); ++i){
        cout << nums[i] << " ";
    }
    cout << endl;
    
    return 0;
}