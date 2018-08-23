#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool DFS(const vector<vector<char>>& board, 
             const string& word, 
             int i, int j, 
             int word_index, 
             vector<vector<bool>>& visited)
    {
        visited[i][j] = true;
        if (word_index + 1 == word.size()) return true;

        // if horizontal/vertical neighbor exists,
        // if that neighbor matches the next letter,
        // and if that neighbor has not been visited:
        // DFS to that neighbor
        if (i + 1 < board.size() && 
            board[i+1][j] == word[word_index + 1] &&
            visited[i+1][j] == false && 
            DFS(board, word, i+1, j, word_index+1, visited)){
            return true;
        }
        if (i - 1 >= 0 && 
            board[i-1][j] == word[word_index + 1] &&
            visited[i-1][j] == false &&
            DFS(board, word, i-1, j, word_index+1, visited)){
            return true;
        }
        if (j + 1 < board[0].size() && 
            board[i][j+1] == word[word_index + 1] &&
            visited[i][j+1] == false &&
            DFS(board, word, i, j+1, word_index+1, visited)){
            return true;
        }
        if (j - 1 >= 0 && 
            board[i][j-1] == word[word_index + 1] &&
            visited[i][j-1] == false &&
            DFS(board, word, i, j-1, word_index+1, visited)){
            return true;
        }

        // if DFS fails, mark it as un-visited for other DFS traversals
        visited[i][j] = false;
        return false;
    }

    bool exist(const vector<vector<char>>& board, const string& word) {
        int rows = board.size();
        int columns = 0;
        // set column size
        if (rows > 0)                  columns = board[0].size();

        // exit if size 0 for any inputs
        if (rows == 0 || columns == 0) return false;
        if (word.size() == 0)          return true;

        // flags to indicate visited
        vector<vector<bool>> visited(rows, vector<bool>(columns, 0));

        // DFS 
        for (int i = 0; i != rows; ++i)
            for (int j = 0; j != columns; ++j)
                if (board[i][j] == word[0] && DFS(board, word, i, j, 0, visited))
                    return true;

        return false;
    }
};


int main(){

    return 0;
}