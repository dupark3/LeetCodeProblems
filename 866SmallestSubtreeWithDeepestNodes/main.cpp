#include <iostream>
#include <queue>
using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 

// BFS of printing
void printTree(TreeNode* root){
    TreeNode* pointer = root;
    queue<TreeNode*> my_queue;

    if (pointer){
        my_queue.push(pointer);
    }
    
    while(!my_queue.empty()){
        if (my_queue.front()->left){
            my_queue.push(my_queue.front()->left);
        }
        if (my_queue.front()->right){
            my_queue.push(my_queue.front()->right);
        }
        
        cout << my_queue.front()->val << " ";
        my_queue.pop();
    }
}

class Solution {
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        
    }
};

int main(){
    TreeNode root(3);
    TreeNode five(5);
    TreeNode one(1);
    TreeNode six(6);
    TreeNode two(2);
    TreeNode zero(0);
    TreeNode eight(8);
    TreeNode seven(7);
    TreeNode four(4);

    root.left = &five;
    root.right = &one;
    five.left = &six;
    five.right = &two;
    one.left = &zero;
    one.right = &eight;
    two.left = &seven;
    two.right = &four;

    printTree(&root);

    Solution solution;
    TreeNode* subtree = solution.subtreeWithAllDeepest(&root);

    TreeNode* pointer = subtree;
    

}