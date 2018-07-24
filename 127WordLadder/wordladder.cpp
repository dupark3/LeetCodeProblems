#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:

    bool oneEditAway(string firstWord, string secondWord){
        // all words have same length assumption given, so no check
        size_t wordSize = firstWord.size();
        bool firstDifferenceEncountered = false;
        for (int i = 0; i != wordSize; ++i){
            if (firstWord[i] != secondWord[i]){
                if (firstDifferenceEncountered){
                    return false;
                }
                firstDifferenceEncountered = true;
            }
        }
        return true;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (find(wordList.begin(), wordList.end(), endWord) == wordList.end()){
            return 0;
        }
        size_t dictSize = wordList.size();
        bool visited[dictSize] = { false };
        
        queue<string> myqueue;
        myqueue.push(beginWord);
        myqueue.push("");

        int shortestSequence = 1;
        while(!myqueue.empty()){
            
            if (myqueue.front() == ""){
                myqueue.pop();
                ++shortestSequence;
                myqueue.push("");
                if (myqueue.front() == ""){
                    break;
                }
            }
            if (myqueue.front() == endWord){
                return shortestSequence;
            }
            
            for (int i = 0; i != dictSize; ++i){
                if (visited[i] == false && oneEditAway(myqueue.front(), wordList[i])){
                    myqueue.push(wordList[i]);
                    visited[i] = true;
                }
            }
 
            myqueue.pop();
        }
        return 0;
    }
};

int main(){
    Solution solution;
    vector<string> dictionary = {"hot","dot","dog","lot","log","cog", "fog", "fob"};

    cout << solution.ladderLength("hit", "fob", dictionary) << endl;

    return 0;
}