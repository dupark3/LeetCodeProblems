#include <iostream>
#include <vector>

using namespace std;

// 1 2 3
// 4 5 6
// 7 8 9

// 1 4 7
// 2 5 8
// 3 6 9

// 1 2 3
// 4 5 6

// 1 4
// 2 5
// 3 6

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        size_t height = A.size();
        size_t width = 0;
        if (!A.empty()){
            width = A[0].size();
        }
        
        vector< vector<int > > B;
        B.resize(width);
        for(int i = 0; i != width; ++i){
            B[i].resize(height, 0);
        }
        
        for (int i = 0; i != height; ++i){
            for (int j = 0; j != width; ++ j){
                B[j][i] = A[i][j]; 
            }
        }
        return B;
    }
};

int main(){
    Solution solution;
    vector< vector<int> > A = {{1,2,3},{4,5,6},{7,8,9}};

    vector< vector<int> > B = solution.transpose(A);

    for (int i = 0; i != B.size(); ++i){
        for (int j = 0; j != B[0].size(); ++j){
            cout << B[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}