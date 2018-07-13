#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() < 2){
            return s.size();
        }

        int currentSubstringLength = 1;
        int maxResult = 0;

        auto first_iter = s.begin();
        auto second_iter = s.begin() + 1;
        bool uniqueCharFlags[262] = {false}; 
        uniqueCharFlags[*first_iter] = true;

        while (second_iter != s.end()){
            if (uniqueCharFlags[*second_iter] == false){
                uniqueCharFlags[*second_iter] = true;
                ++second_iter;
                ++currentSubstringLength;
            } else {
                maxResult = currentSubstringLength > maxResult ? currentSubstringLength : maxResult;
                bool passed = false; 

                while (!passed){
                    uniqueCharFlags[*first_iter] = false;
                    if (*first_iter == *second_iter){
                        passed = true;
                        uniqueCharFlags[*second_iter] = true;
                    }
                    ++first_iter;
                    --currentSubstringLength;
                } 

                ++second_iter;
                ++currentSubstringLength;
            }
        }
        
        return max(maxResult, currentSubstringLength);
    }
};

int main(){
    Solution solution;
    cout << solution.lengthOfLongestSubstring("abcadef") << endl;
    cout << solution.lengthOfLongestSubstring("abcbdef") << endl;
    cout << solution.lengthOfLongestSubstring("abccdef") << endl;
    cout << solution.lengthOfLongestSubstring("pwwkew") << endl;
    cout << solution.lengthOfLongestSubstring("abcdefabbadge") << endl;
    return 0;
}