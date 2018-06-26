#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int numDecodings(const string& s) {
        if (s.empty()){
            return 0;
        }
        
        int total = 0;
        numDecodings(s, total);

        return total;
    }

    void numDecodings(const string& s, int& total){
        // if empty, add one (at the end of recursive calls)
        if (s.empty()){
            ++total;
            return ;
        }

        // if one char possible, call recursion without that letter
        if (s.size() >= 1 && s[0] != '0'){
            numDecodings(s.substr(1), total);
            
            // if two char possible (26 or under), call recursion without those two
            if (s.size() >= 2 && stoi(s.substr(0,2)) <= 26){
                numDecodings(s.substr(2), total);
            }
        }
    }
};

int main(){
    Solution s;
    // 1 7 8 7 8 9 7 7 5 9 9 6 6 2 6
    // 17 8 7 8 9 7 7 5 9 9 6 6 26
    cout << s.numDecodings("1787897759966261825913315262377298132516969578441236833255596967132573482281598412163216914566534565") << endl;
    cout << s.numDecodings("1726") << endl;
    cout << s.numDecodings("002") << endl;
    cout << s.numDecodings("20202000000") << endl;
    return 0;
}