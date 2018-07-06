#include <iostream>
#include <vector>

using namespace std;

// 1 1 3 5 14 42 132 429 1430
vector<int> dp;
int catalan(int n){
    if (dp.empty()){
        dp.push_back(1);
    }
    
    if (n < dp.size()) {
        return dp[n];
    }

    int result = 0;
    
    for (int i = 0; i != n; ++i){
        result += catalan(i) * catalan(n - 1 - i);
    }

    if (n == dp.size()) {
        dp.push_back(result);
    } 
    return result;
}

int main() {
    for (int i = 0; i != 100; ++i){
        cout << "catalan(" << i << "): " << catalan(i) << endl;
    }
    
    return 0;
}