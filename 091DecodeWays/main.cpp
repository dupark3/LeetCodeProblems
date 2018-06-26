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
        if (s.size() >= 1){
            numDecodings(s.substr(1), total);
        }

        // if two char possible (26 or under), call recursion without those two
        if (s.size() >= 2 && stoi(s.substr(0,2)) <= 26){
            numDecodings(s.substr(2), total);
        }
        
    }
};

int main(){
    Solution s;
    
    cout << s.numDecodings("52") << endl;
    cout << s.numDecodings("25") << endl;
    cout << s.numDecodings("226") << endl;
    cout << s.numDecodings("22652") << endl;
    return 0;
}