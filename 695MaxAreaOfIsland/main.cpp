#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector< vector<int> >& grid) {
        int width = grid[0].size();
        int height = grid.size();
        int max_area = 0;

        for (int i = 0; i != height; ++i){
            for (int j = 0; j != width; ++j){
                if (grid[i][j] == 1){
                    int new_area = 0;
                    findLandArea(grid, new_area, i, j);
                    max_area = max(max_area, new_area);
                }
            }
        }
        return max_area;
    }

    void findLandArea(vector< vector<int> >& grid, int& new_area, int i, int j){
        grid[i][j] = 0;
        ++new_area;

        if (i > 0 && grid[i-1][j] == 1){
            findLandArea(grid, new_area, i-1, j);
        } 
        if (i < grid.size() - 1 && grid[i+1][j] == 1){
            findLandArea(grid, new_area, i+1, j);
        }
        if (j > 0 && grid[i][j-1] == 1){
            findLandArea(grid, new_area, i, j-1);
        }
        if (j < grid[i].size() - 1 && grid[i][j+1]){
            findLandArea(grid, new_area, i, j+1);
        }
    }
};

int main(){
    Solution solution;
    vector< vector<int> > grid = { {0,0,1,0,0,0,0,1,0,0,0,0,0},
                                   {0,0,0,0,0,0,0,1,1,1,0,0,0},
                                   {0,1,1,0,1,0,0,0,0,0,0,0,0},
                                   {0,1,0,0,1,1,0,0,1,0,1,0,0},
                                   {0,1,0,0,1,1,0,0,1,1,1,0,0},
                                   {0,0,0,0,0,0,0,0,0,0,1,0,0},
                                   {0,0,0,0,0,0,0,1,1,1,0,0,0},
                                   {0,0,0,0,0,0,0,1,1,0,0,0,0}};

    cout << solution.maxAreaOfIsland(grid) << endl;
    return 0;
}