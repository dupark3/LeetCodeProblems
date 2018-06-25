#include <iostream>
#include <stdexcept> // domain_error
#include <unordered_map> // unordered_map
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        size_t size_nums = nums.size();
        unordered_map<int, int> hashmap;

        for (size_t i = 0; i != size_nums; ++i){
            int complement = target - nums[i];
            auto search = hashmap.find(complement);
            if (search != hashmap.end() && search->second != i)
                return {search->second, i};
            hashmap[nums[i]] = i;
        }
        throw domain_error("No two sum solution");
    }
};

int main()
{
    vector<int> input = {2, 7, 11, 15, -4, 23};
    int target = 11;

    Solution s;
    vector<int> resulting_indices = s.twoSum(input, target);
    try {
        cout << resulting_indices[0] << ", " << resulting_indices[1] << endl;
    } catch(domain_error e){
        cout << e.what() << endl;
    }

    return 0;
}

