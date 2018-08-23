#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool DFS(vector<vector<char>>& board, 
             string word, 
             int i, int j, 
             int word_index, 
             vector<vector<bool>>& visited)
    {
        cout << "checking " << board[i][j] << " with " << word[word_index] << endl;
        visited[i][j] = true;
        if (word_index + 1 == word.size()) return true;

        if (i + 1 < board.size() && 
            visited[i+1][j] == false && 
            board[i+1][j] == word[word_index + 1] &&
            DFS(board, word, i+1, j, word_index+1, visited)){
            return true;
        }
        if (i - 1 >= 0 && 
            visited[i-1][j] == false &&
            board[i-1][j] == word[word_index + 1] &&
            DFS(board, word, i-1, j, word_index+1, visited)){
            return true;
        }
        if (j + 1 < board[0].size() && 
            visited[i][j+1] == false &&
            board[i][j+1] == word[word_index + 1] &&
            DFS(board, word, i, j+1, word_index+1, visited)){
            return true;
        }
        if (j - 1 >= 0 && 
            visited[i][j-1] == false &&
            board[i][j-1] == word[word_index + 1] &&
            DFS(board, word, i, j-1, word_index+1, visited)){
            return true;
        }

        visited[i][j] = false;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int columns = 0;
        if (rows > 0) columns = board[0].size();
        if (rows == 0 || columns == 0) return false;
        if (word.size() == 0) return true;

        vector<vector<bool>> visited;
        visited.resize(rows);
        for (int i = 0; i != rows; ++i){
            visited[i].resize(columns);
        }

        // DFS 
        for (int i = 0; i != rows; ++i){
            for (int j = 0; j != columns; ++j){
                cout << "i : " << i << " j: " << j << endl;
                if (board[i][j] == word[0] && DFS(board, word, i, j, 0, visited)){
                    return true;
                } 
            }
        }

        return false;
    }
};


int main(){

    return 0;
}