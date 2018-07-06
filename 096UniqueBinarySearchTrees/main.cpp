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
        if (n == 0){
            return 1;
        }
        int result = 0;
        for (int i = 0; i != n; ++i){
            result += numTrees(i) * numTrees(n - 1 - i);
        }
        return result;
    }
};

int main(){
    Solution solution;

    cout << solution.numTrees(3) << endl;
    return 0;
}