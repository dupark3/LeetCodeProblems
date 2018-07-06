#include <iostream>
#include <vector>

using namespace std;

// 1 1 3 5 14 42 132 429 1430

int catalan(int n){
    if (n == 0){
        return 1;
    }
    int result = 0;
    for (int i = 0; i != n; ++i){
        result += catalan(i) * catalan(n - 1 - i);
    }
    return result;
    
}

int main() {
    for (int i = 0; i != 10; ++i){
        cout << "catalan(" << i << "): " << catalan(i) << endl;
    }
    
    return 0;
}