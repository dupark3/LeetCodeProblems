#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        
        string prefix = strs[0];

        for (int i = 1; i != strs.size() && !prefix.empty(); ++i){
            // truncate prefix if next word is shorter than prefix
            if (prefix.size() > strs[i].size())
                prefix = prefix.substr(0, strs[i].size());

            // iterate through and truncate if difference found
            for (int j = 0; j < strs[i].size(); ++j){
                if (prefix[j] != strs[i][j]){
                    prefix = prefix.substr(0, j);
                    break;
                }
            }
        }
        return prefix;
    }
};

int main(){
    Solution solution;
    string dog = "cat";
    
    vector<string> words = {"fix", "flow", "flint"};
    cout << solution.longestCommonPrefix(words) << endl;
    return 0;
}