#include <iostream>

using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int total = 0;
        for (uint64_t i = 1; i <= n; i = i << 1){
            if (i & n){
                ++total;
            }
        }
        return total;
    }
};

int main(){
    Solution solution;
    uint32_t max = 2147483649;
    cout << max << endl;

    cout << solution.hammingWeight(0) << endl; // 0 => 0
    cout << solution.hammingWeight(5) << endl; // 101 => 2
    cout << solution.hammingWeight(30) << endl; // 11110 => 4
    cout << solution.hammingWeight(128) << endl; // 10000000 => 1
    cout << solution.hammingWeight(2147483648) << endl; // 10000000 => 1

    return 0;
}