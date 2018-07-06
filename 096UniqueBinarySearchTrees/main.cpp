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



class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1,0);
        dp[0] = 1;
        dp[1] = 1;
        
        if (n <= 1) {
            return dp[n];
        }
        
        for (int i = 2; i <= n; ++i){
            dp[i] = 0;
            for (int j = 1; j <= i; ++j){
                dp[i] += (dp[i - j] * dp[j - 1]);
            }
        }
        
        return dp[n];
    }
};

int main(){
    Solution solution;
    for (int i = 0; i != 19; ++i){
        cout << solution.numTrees(i) << endl;
    }
    
    return 0;
}