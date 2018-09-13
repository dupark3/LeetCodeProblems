#include <cctype>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        if (s.empty()){
            return true;
        }
        
        int i = 0;
        int j = s.size() - 1;

        // while left < right
        while (i < j){
            // ignore all nonalpha chars
            while (i < s.size() && !isalnum(s[i])) ++i;
            while(j >= 0 && !isalnum(s[j])) --j;
            if (tolower(s[i]) != tolower(s[j])){
                return false;
            }
            ++i;
            --j;
        }

        return true;
    }
};

int main(){
    Solution solution;

    // True tests
    cout << solution.isPalindrome("race car") << endl; // 1
    cout << solution.isPalindrome("A man, a plan, a canal: Panama") << endl; // 1
    cout << solution.isPalindrome("") << endl; // 1

    // False tests
    cout << solution.isPalindrome("race a car") << endl; // 0
    return 0;
}