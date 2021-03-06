#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canJump2(const vector<int>& nums){
        int target = nums.size() - 1;

        for (int i = nums.size() - 2; i >= 0; --i){
            if (i + nums[i] >= target){
                target = i;
            }
        }

        return target == 0;
    }

    bool canJump(const vector<int>& nums) {
        last_index = nums.size() - 1;
        
        vector<bool> visited(nums.size());
        
        if (nums.size() == 0)
            return true;

        if (dfs(nums, 0, visited))
            return true;

        return false;
    }
private:
    bool dfs(const vector<int>& nums, int index, vector<bool>& visited){
        // traverse from max jump to negative max jump
        visited[index] = true;

        if (index == last_index)
            return true;
        
        if (nums[index] == 0)
            return false;
        
        for (int i = nums[index]; i >= -nums[index]; --i){
            if (inRange(index + i) && 
                !visited[index + i] && 
                dfs(nums, index + i, visited))
                return true;
        }

        visited[index] = false;
        return false;
    }

    bool inRange(int index){
        return index >= 0 && index <= last_index;
    }

    int last_index;
};

int main() {
    Solution solution;
    vector<int> nums = {2,3,1,1,4};
    
    if (solution.canJump2(nums)){
        cout << "can jump" << endl;
    } else {
        cout << "can't jump" << endl;
    }
    return 0;
}