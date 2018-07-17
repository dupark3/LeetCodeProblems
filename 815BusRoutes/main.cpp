#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

void printVector(const vector<int>& vector){
    int size = vector.size();
    for (int i = 0; i != size; ++i){
        cout << vector[i] << " ";
    }
    cout << endl;
}

class BusGraphNode{
friend class Solution;
public:
    BusGraphNode(int n) : BusNumber(n), next(0) { }
private:
    int BusNumber;
    BusGraphNode* next;
    vector<BusGraphNode*> transfer;
};

class Solution {
public:
    int numBusesToDestination(vector< vector<int> >& routes, int start, int end) {
        int numberOfBuses = routes.size();
        int currentStop = start;
        
        unordered_map<int, vector<BusGraphNode*>> busConnections;

        vector< BusGraphNode* > buses;
        for (int i = 0; i != numberOfBuses; ++i){
            buses.push_back(new BusGraphNode(routes[i][0]));
            BusGraphNode* temp = buses[i];
            
            auto it = busConnections.find(routes[i][0]);
            if (it != busConnections.end()){
                it->second.push_back(temp);
            } else {
                busConnections[routes[i][0]].push_back(temp);
            }

            for (int j = 0; j != routes[i].size() - 1; ++j){
                temp->next = new BusGraphNode(routes[i][j + 1]);
                temp = temp->next;

                auto it = busConnections.find(routes[i][j+1]);
                if (it != busConnections.end()){
                    it->second.push_back(temp);
                } else {
                    busConnections[routes[i][j+1]].push_back(temp);
                }
            }
            temp->next = buses[i]; // connect back to the head of route
        }

        // connect all transfers to each other
        for (auto i = busConnections.begin(); i != busConnections.end(); ++i){
            for (int j = 0; j != i->second.size(); ++j){
                for (int k = 0; k != i->second.size(); ++k){
                    if (j != k){
                        cout << "connecting " << i->first << " transfers" << endl;
                        i->second[j]->transfer.push_back(i->second[k]);
                    }
                }
            }
        }

/*        // find all possible bus number to ride first
        vector<int> startingBuses;
        for (int i = 0; i != numberOfBuses; ++i){
            for (int j = 0; j != routes[i].size(); ++j){
                if (start == routes[i][j]){
                    startingBuses.push_back(i);
                    break;
                }
            }
        }*/
        
        vector<int> viableTransfers;

        // go through every first bus and go to the end, pushing back 
        // number of buses taken if we reach the end
        auto it = busConnections.find(start);
        int possibleStartingBuses = 0;
        if (it != busConnections.end()){
            possibleStartingBuses = it->second.size();
            cout << "starting possible at "<< possibleStartingBuses << endl;
        } 
        for (int i = 0; i != possibleStartingBuses; ++i){
            int transfers = 1;

            // shortest route, so breadth first search (only count transfers)
            queue<int> myqueue;


            if (currentStop == end){
                viableTransfers.push_back(transfers);
            }
        }

        // sort and return the smallest element if possible
        sort(viableTransfers.begin(), viableTransfers.end());
        return viableTransfers.size() > 0 ? viableTransfers[0] : -1;
        
    }
};

int main(){
    Solution solution;
    vector< vector<int> > routes = { {1, 3, 7}, {2, 6, 7}, {2, 9, 6}};

    cout << solution.numBusesToDestination(routes, 1, 6) << endl;

    return 0;
}