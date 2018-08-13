#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        // 0 2 1 3 BAD, middle two next to each other
        // middle "turn" should be on the end
        // 2 5 1 4 0 3
        // 2 4 1 3 0
        // 1 2 0
        if (nums.empty()){
            return;
        }

        sort(nums.begin(), nums.end());
        vector<int> copy(nums.size());

        // start at the last even number index
        int copyindex = nums.size() - 1;
        if (copyindex % 2 == 1){
            --copyindex;
        }
        int numsindex = 0;

        while(copyindex >= 0){
            copy[copyindex] = nums[numsindex++];
            copyindex -= 2;
        }
        
        // start over at the last odd number index
        copyindex = nums.size() - 1;
        if (copyindex % 2 == 0){
            --copyindex;
        }

        while(copyindex >= 0){
            copy[copyindex] = nums[numsindex++];
            copyindex -= 2;
        }

        nums = copy;
    }
};

int main(){
    Solution solution;
    vector<int> nums {2, 5, 1, 2};
    for (int i : nums){
        cout << i << ' ';
    }
    cout << endl;


    solution.wiggleSort(nums);
    for (int i : nums){
        cout << i << ' ';
    }
    cout << endl;
}