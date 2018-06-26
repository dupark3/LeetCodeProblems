#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int numDecodings(const string& s) {
        int size = s.length() + 1;
        if (size == 1 || s[0] == '0'){
            return 0;
        } else if (size == 2){
            return 1;
        }
                
        vector<int> possibilities(size, 0);
        possibilities[0] = 1;
        possibilities[1] = 1;

        for (int i = 2; i < size; ++i){
            if (s[i-1] >= '1' && s[i-1] <= '9'){
                possibilities[i] += possibilities[i-1];
            }
            if (s[i-2] == '1' || (s[i-2] == '2' && s[i-1] >= '0' && s[i-1] <= '6')){
                possibilities[i] += possibilities[i-2];
            }
        }
        

        return possibilities[size - 1];
    }

    
};

int main(){
    Solution s;
    // # of digits = 4 
    // # of tens = 2
    // # of overlapping tens = 2
    // 
    // answer : 3          0123
    cout << s.numDecodings("22619920") << endl;
    cout << s.numDecodings("1787897759966261825913315262377298132516969578441236833255596967132573482281598412163216914566534565") << endl;
    cout << s.numDecodings("1726") << endl;
    cout << s.numDecodings("002") << endl;
    cout << s.numDecodings("20202000000") << endl;
    return 0;
}