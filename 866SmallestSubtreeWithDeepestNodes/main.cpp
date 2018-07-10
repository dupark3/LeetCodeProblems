#include <algorithm>
#include <climits>
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
 

// BFS of printing, nonmember just to support this problem
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

    cout << endl;
}

int maxDepth(TreeNode* node){
    if (!node){
        return 0;
    } else {
        int left_depth = maxDepth(node->left);
        int right_depth = maxDepth(node->right);
        return max(left_depth, right_depth) + 1;
    }
}

class Solution {
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        // check max depth to the left and to the right
        // if equal, return that node
        // if left is greater, pointer = root->left, similar for right side
        if (!root){
            return 0;
        }

        TreeNode* pointer = root;
        while (pointer){
            // get left max depth
            int left_depth = maxDepth(pointer->left);

            // get right max depth
            int right_depth = maxDepth(pointer->right);

            // compare and reset pointer or return current node
            if (left_depth == right_depth){
                return pointer;
            } else {
                pointer = left_depth > right_depth ? pointer->left : pointer->right;
            }
        }
        

        return pointer;
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
    TreeNode ten(10);


    root.left = &five;
    root.right = &one;
    five.left = &six;
    five.right = &two;
    one.left = &zero;
    one.right = &eight;
    two.left = &seven;
    two.right = &four;
    seven.left = &ten;

    printTree(&root);

    Solution solution;
    TreeNode* subtree = solution.subtreeWithAllDeepest(&root);

    printTree(subtree);
    

}