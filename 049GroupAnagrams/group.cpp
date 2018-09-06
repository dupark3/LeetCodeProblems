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
        while(!strs.empty()){
            bool anagramFound = false;
            for (int i = 0; i != groups.size(); ++i){
                if(isAnagram(groups[i][0], strs.back())){
                    groups[i].push_back(strs.back());
                    anagramFound = true;
                    break;
                }
            }
            if (!anagramFound){
                groups.push_back({strs.back()});
            }
            strs.pop_back();
        }

        return groups;
    }

    bool isAnagram(const string& s1, const string& s2){
        if (s1.size() != s2.size()){
            return false;
        }
        
        unordered_map<char, int> char_map;
        for (int i = 0; i != s1.size(); ++i){
            char_map[s1[i]]++;
            char_map[s2[i]]--;
        }
        
        for (int i = 0; i != s1.size(); ++i){
            if (char_map[s1[i]] != 0){
                return false;
            }
        }

        return true;
    }
};

int main(){
    Solution solution;
    vector<string> strs = {"eat", "ate", "cat", "atc", "bat", "tab"};
    vector<vector<string>> result = solution.groupAnagrams(strs);

    for (int i = 0; i != result.size(); ++i){
        for (int j = 0; j != result[i].size(); ++j){
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}