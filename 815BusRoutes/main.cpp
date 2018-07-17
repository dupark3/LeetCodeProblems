#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void printVector(const vector<int>& vector){
    int size = vector.size();
    for (int i = 0; i != size; ++i){
        cout << vector[i] << " ";
    }
    cout << endl;
}

class Solution {
public:
    int numBusesToDestination(vector< vector<int> >& routes, int start, int end) {
        int numberOfBuses = routes.size();
        int currentStop = start;

        vector<int> startingBuses;

        for (int i = 0; i != numberOfBuses; ++i){
            for (int j = 0; j != routes[i].size(); ++j){
                if (start == routes[i][j]){
                    startingBuses.push_back(i);
                    break;
                }
            }
        }
        printVector(startingBuses);

        vector<int> viableTransfers = { -1 };
        int transfers = 1;

        for (int i = 0; i != numberOfBuses; ++i){

        }

        if (currentStop == end){
            viableTransfers.push_back(transfers);
        }
        
        sort(viableTransfers.begin(), viableTransfers.end());
        return viableTransfers[viableTransfers.size() - 1];
        
    }
};

int main(){
    Solution solution;
    vector< vector<int> > routes = { {1, 3, 7}, {2, 6, 7}, {2, 9, 6}};

    cout << solution.numBusesToDestination(routes, 1, 6) << endl;

    return 0;
}