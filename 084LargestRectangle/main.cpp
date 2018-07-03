#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int columns = heights.size();
        int rows = 0;
        for (int i = 0; i != columns; ++i){
            if (heights[i] > rows){
                rows = heights[i];
            }
        }
        cout << "COLUMNS : " << columns << endl
             << "ROWS : " << rows << endl;

        bool matrix[rows][columns];
        for (int i = 0; i != rows; ++i){
            for (int j = 0; j != columns; ++j){
                if (heights[j] > i){
                    matrix[i][j] = true;
                } else {
                    matrix[i][j] = false;
                }
            }
        }

        for (int i = 0; i != rows; ++i){
            for (int j = 0; j != columns; ++j){
                cout << matrix[i][j];
            }
            cout << endl;
        }
    }
};

int main(){
    Solution solution;
    vector<int> input = {2,1,5,6,2,3};
    solution.largestRectangleArea(input);
    return 0;
}