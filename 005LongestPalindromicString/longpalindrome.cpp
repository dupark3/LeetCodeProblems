#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int length = s.size();

        if (length < 2){
            return s;
        }

        for (int i = length; length >= 0; --i){
            for (int j = 0; i + j != length + 1; ++j){
                //cout << "checking " << s.substr(j, i) << " with j = " << j << " and i = " << i << endl;
                if (checkPalindrome(s.substr(j, i))){
                    return s.substr(j, i);
                }
            }
        }
    }

    bool checkPalindrome(string s){
        int i = 0;
        int j = s.size() - 1;

        while (i < j){
            if (s[i++] != s[j--]){
                return false;
            }
        }
        return true;
    }
};

int main(){
    Solution solution;
    cout << solution.checkPalindrome("abcba") << endl; //1
    cout << solution.checkPalindrome("abad") << endl; //0
    cout << solution.checkPalindrome("abba") << endl; //1
    cout << solution.longestPalindrome("thisisthelongestabcdefgfedcbapalindrome") << endl;
    return 0;
}