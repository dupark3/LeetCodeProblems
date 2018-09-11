#include <iostream>

using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2){
            return 0;
        } else if (n <= 4){
            return n - 2; // 1 if n=3, 2 if n=4
        }

        int numberOfPrimes = 2; // 2 and 3
        
        for (int i = 5; i < n; i += 2){
            // ignoring all evens
            if(checkPrime(i)){
                ++numberOfPrimes;
            }
        }
        return numberOfPrimes;
    }

    bool checkPrime(int x){
        if (x % 3 == 0){
            return false;
        } 
        for (int i = 5; i * i <= x; i += 6){
            if (x % i == 0 || x % (i + 2) == 0){
                return false;
            }
        }
        return true;
    }
};

int main(){
    Solution solution;

    cout << solution.countPrimes(10) << endl; // 4
    cout << solution.countPrimes(0) << endl; // 0
    cout << solution.countPrimes(1) << endl; // 0
    cout << solution.countPrimes(1000) << endl; // 168

    return 0;
}