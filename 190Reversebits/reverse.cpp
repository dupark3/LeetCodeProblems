#include <iostream>

using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int result = 0; 
        for (int i = 0; i != 32; ++i){
            int mask = (1 << i);
            result += (n & mask) << (31 - i);
            // result += (n << 31 - i) >> 31 << (31 - i);
            // result += ((n >> i) << 31 >> 31 << (31 - i));
        }
        return result;
    }
};

int main(){
    Solution solution;
    cout << solution.reverseBits(43261596) << endl;
    return 0;
}