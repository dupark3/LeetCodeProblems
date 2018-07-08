#include <iostream>

using namespace std;


 // Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 

class Solution {
public:
    bool isSymmetric(TreeNode* leftroot, TreeNode* rightroot){

    }

    bool isSymmetric(TreeNode* root) {
        if (root && root->left && root->right && root->left->val == root->right->val){
            return isSymmetric(root->left, root->right);
        }
    }
};

int main() {
    Solution solution;

    TreeNode root(1);
    TreeNode two(2);
    TreeNode two2(2);
    TreeNode three(3);
    TreeNode three2(3);
    TreeNode four(4);
    TreeNode four2(4);

    root.left = &two;
    root.right = &two2;
    two.left = &three;
    two.right = &four;
    two2.left = &four2;
    two2.right = &three2;

    cout << solution.isSymmetric(&root) << endl;

    return 0;
}