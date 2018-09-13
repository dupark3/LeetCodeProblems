#include <iostream>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        /*2147483648
        46340 * 46340 = 2147395600
        46340 / 2 = 23170*/
        if (x == 0){
            return 0;
        }
        int n = 23170;
        int right = 46340;
        int left = 0;

        while (true){
/*            cout << "left  : " << left << endl;
            cout << "right : " << right << endl;
            cout << "n     : " << n << endl;*/
            if (n * n == x){
                return n;
            } else if (n * n < x){
                /*cout <<"    going right" << endl;*/
                left = n;
                int increment = (right - n) / 2;
                if (increment == 0) {
                    if ((n + 1) * (n + 1) > x)
                        return n;
                    else
                        return n + 1;
                }
                n += increment;
            } else if (n * n > x){
                /*cout <<"    going left" << endl;*/
                right = n;
                int increment = (n - left) / 2;
                if (increment == 0) return n - 1;
                n -= increment;
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