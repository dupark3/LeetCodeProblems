#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/*class Node{
friend class UniqueBinarySearchTree;
public:
    Node() { }
    Node(int val) : element(val) { elements[val]; } 

private:
    int element;
    unordered_map<int, int> elements;
    Node* left;
    Node* right;
};

class UniqueBinarySearchTree{
public:
    UniqueBinarySearchTree() : head(0){ }
    UniqueBinarySearchTree(int n) {
        head = new Node();

    }

private:
    Node* head;
};
*/

vector<int> dp;

class Solution {
public:
    int numTrees(int n) {
        if (dp.empty()){
            dp.push_back(1);
        }
        
        if (n < dp.size()) {
            return dp[n];
        }

        int result = 0;
        
        for (int i = 0; i != n; ++i){
            result += numTrees(i) * numTrees(n - 1 - i);
        }

        if (n == dp.size()) {
            dp.push_back(result);
        } 
        return result;
    }
};

int main(){
    Solution solution;

    cout << solution.numTrees(3) << endl;
    return 0;
}