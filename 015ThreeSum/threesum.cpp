#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int numsSize = nums.size();
        vector<vector<int>> result;
        
        if (numsSize < 3){
            return result;
        }
        
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i != numsSize; ++i){
            for (int j = i + 1; j != numsSize; ++j){
                for (int k = j + 1; k != numsSize; ++k){
                    if (nums[i] + nums[j] + nums[k] == 0){
                        vector<int> temp = {nums[i], nums[j], nums[k]};
                        if (find(result.begin(), result.end(), temp) == result.end()){
                            result.push_back(temp);  
                        }
                    } 
                        
                }
            }
        }
        return result;
    }
};

int main() {
    vector<int> input = {-1, 0, 1, 2, -1, -4};
    // -4 -1 -1 0 1 2
    Solution solution;
    vector<vector<int>> answer = solution.threeSum(input);

    for (int i = 0; i != answer.size(); ++i){
        for (int j = 0; j != answer[i].size(); ++j){
            cout << answer[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}