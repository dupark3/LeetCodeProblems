#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> groups;

        // loop through words and find matching anagram if any
        for (int i = 0; i != strs.size(); ++i){
            bool anagramFound = false;
            for (int j = 0; j != groups.size(); ++j){
                if(isAnagram(groups[j][0], strs[i])){
                    groups[j].push_back(strs[i]);
                    anagramFound = true;
                    break;
                }
            }
            if (!anagramFound){
                groups.push_back({strs[i]});
            }
        }

        return groups;
    }

    bool isAnagram(const string& s1, const string& s2){
        if (s1.size() != s2.size()){
            return false;
        }
        
        unsigned int bitMap = 0;
        for (int i = 0; i != s1.size(); ++i){
            bitMap ^= s1[i];
            bitMap ^= s2[i];
        }
        
        if (bitMap == 0){
            return true;
        } 
        return false;
    }
};

int main(){
    Solution solution;
    vector<string> strs = {"bat", "eat", "ate", "tab", "cat"};
    vector<vector<string>> result = solution.groupAnagrams(strs);

    for (int i = 0; i != result.size(); ++i){
        for (int j = 0; j != result[i].size(); ++j){
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}