#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        size_t numOfPrereqs = prerequisites.size();
        
    }
};

int main(){
    Solution solution;

    vector<pair<int, int>> prereqs = { {0, 1}, {4, 3}, {4, 2}, {3, 2} };
    if (solution.canFinish(4, prereqs)){
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }

    vector<pair<int, int>> prereqs2 = { {0, 1}, {1, 0} };
    if (solution.canFinish(2, prereqs2)){
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }

    return 0;
}