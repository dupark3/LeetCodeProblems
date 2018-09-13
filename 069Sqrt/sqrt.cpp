#include <iostream>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if (x <= 1)
            return x;

        int left = 1;
        int right = x/2;

        while (true){
            int mid = left + ((right - left) / 2);
            if (mid > x / mid){  
                // going left
                right = mid;
            } else {
                // going right
                if ((mid + 1) > x / (mid + 1))
                    return mid;
                left = mid + 1;
            }
        }
    }
};

int main(){
    Solution solution;
    cout << solution.mySqrt(4) << endl; // 2
    cout << solution.mySqrt(8) << endl; // 2
    cout << solution.mySqrt(0) << endl; // 0
    cout << solution.mySqrt(101) << endl; // 10
    cout << solution.mySqrt(99) << endl; // 9
    cout << solution.mySqrt(2147483647) << endl; // 9
    return 0;
}