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


class Solution {
public:
    int maxDepth(TreeNode* node){
        if (!node){
            return 0;
        } else {
            int left_depth = maxDepth(node->left);
            int right_depth = maxDepth(node->right);
            return max(left_depth, right_depth) + 1;
        }       
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if (!root){
            return 0;
        }

        TreeNode* pointer = root;
        while (pointer){
            int left_depth = maxDepth(pointer->left);
            int right_depth = maxDepth(pointer->right);

            // if left and right depth are equal, current node contains all deepest nodes
            if (left_depth == right_depth){
                return pointer;
            } else {
                pointer = left_depth > right_depth ? pointer->left : pointer->right;
            }
        }
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

    printTree(subtree);
    

}