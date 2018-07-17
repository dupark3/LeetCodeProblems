#include <algorithm>
#include <iostream>
#include <memory> //smart pointers
#include <queue>
#include <unordered_map>
#include <vector>


using namespace std;


class Solution {
    class BusGraphNode{
    friend class Solution;
    public:
        BusGraphNode(int n) : stopNumber(n), next(0), containsDestination(0), visited(0) { }

    private:
        int stopNumber;
        BusGraphNode* next;
        vector< BusGraphNode* > transfer;
        bool containsDestination;
        bool visited;
    };
public:

    int numBusesToDestination(vector< vector<int> >& routes, int start, int end) {
        if (start == end){
            return 0;
        }
        
        unordered_map<int, vector< BusGraphNode* > > busConnections;

        // vector< BusGraphNode* > buses;
        for (int i = 0; i != routes.size(); ++i){
            BusGraphNode* startingNode = new BusGraphNode(routes[i][0]);
            BusGraphNode* temp = startingNode;

            // save the current node in hashmap
            auto it = busConnections.find(routes[i][0]);
            if (it != busConnections.end()){
                it->second.push_back(temp);
            } else {
                busConnections[routes[i][0]].push_back(temp);
            }
            
            // if current bus route contains destination, mark this loop as found
            bool destinationFound = false;
            if (routes[i][0] == end){
                destinationFound = true;
            }

            // go through the rest of the bus route and save in hashmap
            for (int j = 0; j != routes[i].size() - 1; ++j){
                temp->next = new BusGraphNode(routes[i][j + 1]);
                temp = temp->next;

                auto it = busConnections.find(routes[i][j+1]);
                if (it != busConnections.end()){
                    it->second.push_back(temp);
                } else {
                    busConnections[routes[i][j+1]].push_back(temp);
                }

                if (routes[i][j+1] == end){
                    destinationFound = true;
                }
            }
            
            temp->next = startingNode; // connect back to the head of route
            if (destinationFound){
                temp = startingNode;
                do{
                    temp->containsDestination = true;
                    temp = temp->next;
                } while (temp != startingNode);
            }
        }

        // connect all transfers to each other
        for (auto i = busConnections.begin(); i != busConnections.end(); ++i){
            for (int j = 0; j != i->second.size(); ++j){
                for (int k = 0; k != i->second.size(); ++k){
                    if (j != k){
                        i->second[j]->transfer.push_back(i->second[k]);
                    }
                }
            }
        }
        
        vector<int> possibleBusesTaken;

        // find all possible starting nodes
        vector< BusGraphNode* > startingNodes;
        auto it = busConnections.find(start);
        int possibleStartingBuses = 0;
        if (it != busConnections.end()){
            possibleStartingBuses = it->second.size();
            for (int i = 0; i != possibleStartingBuses; ++i){
                startingNodes.push_back(it->second[i]);
            }
        } 

        // go through every first bus and go to the end, pushing back 
        // number of buses taken if we reach the end
        for (int i = 0; i != possibleStartingBuses; ++i){
            BusGraphNode* startingBusStop = startingNodes[i];
            int busesTaken = 1;

            // shortest route, so breadth first search (only count transfers)
            queue< BusGraphNode* > myqueue;
            myqueue.push(startingBusStop);
            myqueue.push(0);
            
            while (!myqueue.empty()){
                BusGraphNode* currentNode = myqueue.front();
                if (currentNode == 0){
                    ++busesTaken;
                    myqueue.pop();
                    myqueue.push(0);
                    if (myqueue.front() == 0){
                        break;
                    }
                    continue;
                } 
                
                if (currentNode->containsDestination){
                    possibleBusesTaken.push_back(busesTaken);
                    break;
                }
                
                // push all transfers from current bus route, mark current bus as visited
                do {
                    if (currentNode->transfer.size() > 0){
                        for (int i = 0; i != currentNode->transfer.size(); ++i){
                            if (currentNode->transfer[i]->visited == false){
                                myqueue.push(currentNode->transfer[i]);
                            }
                            
                        }
                    }
                    currentNode->visited = true;
                    currentNode = currentNode->next;
                } while(currentNode != myqueue.front());
                myqueue.pop();
            }
            
        }

        // deallocate memory, but removed buses[i] to improve space
/*        for (int i = 0; i != routes.size(); ++i){
            BusGraphNode* temp = buses[i];
            BusGraphNode* next = temp->next;
            temp->next = 0;
            for (int j = 0; j != routes[i].size(); ++j){
                temp = next;
                next = temp->next;
                delete temp;
            }
        }*/



        // sort and return the smallest element if possible
        sort(possibleBusesTaken.begin(), possibleBusesTaken.end());
        return possibleBusesTaken.size() > 0 ? possibleBusesTaken[0] : -1;
        
    }
};


int main(){
    Solution solution;
    vector< vector<int> > routes = {{17,19,22,25,26,49,59},{2,6,30},{8,15,16,26,41,49,50,55,58,59,64},{7,11,17,21,26,31,35,43},{8,11,15,29},{17,19,21,23,24,26,33,43,46,47,64},{7,11,22,32,34,45,47,48,55,63},{1,7,14,26,37,40,45,49,52,58,63},{13,37,43,62},{12,40},{2,4,21,24,32,39,43,44,48,50,52,56},{19,21,24,30,32,35,37,56,60},{8,10,16,18,29,33,37,42,62,63}};

    cout << solution.numBusesToDestination(routes, 17, 60) << endl;

    return 0;
}