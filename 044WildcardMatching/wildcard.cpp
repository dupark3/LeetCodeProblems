#include <iostream>
#include <string>

using namespace std;

// ? can match any ONE char
// * can match ANY sequence of chars, including empty space

class Solution {
public:
    bool isMatch(string text, string pattern) {
        //return isMatch(text, pattern, 0, 0, text.size(), pattern.size());
        int text_length = text.size(), pattern_length = pattern.size();
        int i = 0, j = 0;
        int i_star = -1, j_star = -1;
        // abaa *??*b
        // adceb *a*b

        for (i, j; i < text_length; ++i, ++j){
            if (pattern[j] == '*'){
                // new star encountered, update
                i_star = i;
                j_star = j;
                --i;
            }
            else {
                if (pattern[j] != text[i] && pattern[j] != '?'){
                    // mismatch
                    if (i_star >= 0){
                        i = i_star++;
                        j = j_star;
                    } else {
                        return false;
                    }
                }
            } 
        }
        while (pattern[j] == '*'){
            ++j;
        }
        return j == pattern_length;
    }
private:
    /*bool isMatch(string text, string pattern, int i, int j, int text_size, int pattern_size){
        cout << "i: " << i << " j: " << j << endl;
        if (i == text_size && j == pattern_size){
            cout << "i and j have reached the end. i: " << i << " j: " << j << endl;
            return true;
        }

        if (pattern[j] == '?' || pattern[j] == text[i]){
            cout << "one char matched " << text[i] << " = " << pattern[j] << endl;
            return isMatch(text, pattern, ++i, ++j, text_size, pattern_size);
        } else if (pattern[j] == '*'){
            cout << "* encountered, recursion starting" << endl;
            while (pattern[j] == '*'){
                ++j;
            }
            if (j == pattern_size){
                return true;
            }
            for (int k = i; k != text_size; ++k){
                if (isMatch(text, pattern, k, j, text_size, pattern_size)){
                    return isMatch(text, pattern, ++k, ++j, text_size, pattern_size);
                }
            }
        }
        return false;
        
    }*/
};

int main(){
    Solution solution;
    if (solution.isMatch("adceb", "*a*b")){
        cout << "Match" << endl;
    } else {
        cout << "No Match" << endl;
    }
    
    return 0;
}