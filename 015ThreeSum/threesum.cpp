#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        
        if (nums.size() < 3){
            return result;
        }
        
        sort(nums.begin(), nums.end());
        
        for (auto i = nums.begin(); i + 2 != nums.end(); ++i){
            //cout << "for loop" << endl;
            if (i != nums.begin() && *i == *(i - 1)){
                // if first number is the same starting point as before, ignore this starting point
                continue;
            }
            for (auto j = i + 1; j + 1 != nums.end(); ++j){
                while (j != nums.end() && *j == *(j - 1) && (j - 1) != i){
                    // if second number is the same starting point as before,
                    ++j;
                }
                if (j == nums.end()){
                    break;
                }
                //auto k = my_binary_search(j + 1, nums.end(), (*i + *j) * -1, nums.end());
                if (binary_search(j+1, nums.end(), (*i + *j) * -1)){
                    result.push_back({*i, *j, (*i + *j) * -1});
                }
                
            }
        }

        return result;
    }
};

int main() {
    vector<int> input = {0, 0, 0, 0};
    vector<int> input2 = {1, 1, -2, -3, 3, 0, 2, 2, -5, 10, -10, 100, -50, -50};
    Solution solution;
    vector<vector<int>> answer = solution.threeSum(input2);

    for (int i = 0; i != answer.size(); ++i){
        for (int j = 0; j != answer[i].size(); ++j){
            cout << answer[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}