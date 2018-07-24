#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
public:
    void addNextWords(const string& word, queue<string>& toVisit, unordered_set<string>& wordList){
        wordList.erase(word);
        size_t wordSize = word.length();
        
        for (int i = 0; i != wordSize; ++i){
            string newWord = word;
            for (int j = 0; j != 26; ++j){
                newWord[i] = 'a' + j;
                if (wordList.find(newWord) != wordList.end()){
                    toVisit.push(newWord);
                    wordList.erase(newWord);
                }
            }
        }
    }

    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        if (beginWord == endWord){
            return 1;
        } else if (wordList.find(endWord) == wordList.end()){
            return 0;
        }
        queue<string> toVisit;
        addNextWords(beginWord, toVisit, wordList);
        int answer = 2;

        while(!toVisit.empty()){
            int toVisitSize = toVisit.size();
            for (int i = 0; i != toVisitSize; ++i){
                if (toVisit.front() == endWord){
                    return answer;
                }
                addNextWords(toVisit.front(), toVisit, wordList);
                toVisit.pop();
            }
            ++answer;
        }
        return 0;
    }
        int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
            unordered_set<string> wordSet;
            int wordListSize = wordList.size();
            for (int i = 0; i != wordListSize; ++i){
                wordSet.insert(wordList[i]);
            }
            
            return ladderLength(beginWord, endWord, wordSet);
        }
};

int main(){
    Solution solution;
    vector<string> dictionary = {"hot","dot","dog","lot","log","cog", "fog", "fob"};

    cout << solution.ladderLength("hit", "fob", dictionary) << endl;

    return 0;
}