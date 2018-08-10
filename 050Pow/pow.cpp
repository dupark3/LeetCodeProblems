#include <iostream>


using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        bool negative = false;
        if (n == 0){
            return 1;
        } else if (n < 0){
            negative = true;
            n *= -1;
        }
        
        double answer = x;
        for (long long i = 1; i < n; ){
            if (i * 2 < n){
                cout << "double double" << i << endl;
                i *= 2;
                answer *= answer;
            } else {
                cout << "recursion" << i << endl;
                answer *= myPow(x, n - i);
                i = n;
            }

        }
        
        if (negative){
            return (double)1/answer;
        } else {
            return answer;
        }
    }
};

int main(){
    Solution solution;

    cout << solution.myPow(2, 10) << endl;
    cout << solution.myPow(2.10000, 3) << endl;
    //cout << solution.myPow(.000001, 2147483647) << endl;

    return 0;
}