#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> groups;
        unordered_map<string, int> anagramMap;
        int index = 0;

        // sort each string and put it into hashmap
        // if it already exists, pushback into index 
        for (int i = 0; i != strs.size(); ++i){
            string sorted = strs[i];
            sort(sorted.begin(), sorted.end());
            if (anagramMap.find(sorted) != anagramMap.end()){
                groups[anagramMap[sorted]].push_back(strs[i]);
            } else {
                anagramMap[sorted] = index++;
                groups.push_back({strs[i]});
            }
            
        }

        return groups;
    }
};

int main(){
    Solution solution;
    vector<string> strs = {"bat", "eat", "ate", "tab", "cat"};
    vector<vector<string>> result = solution.groupAnagrams(strs);

    // print vector of vector
    for (int i = 0; i != result.size(); ++i){
        for (int j = 0; j != result[i].size(); ++j){
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}