#include <iostream>
#include <vector>

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
    bool isValidBST(TreeNode* root) {
        // go all the way down to the left
        // must be the smallest item there
        // left, mid, then right
        if (!root){
            return true;
        }
        
        vector<int> nums;
        orderedLoad(root, nums);
        for (int i = 0; i != nums.size() - 1; ++i){
            if (nums[i] >= nums[i + 1]){
                return false;
            }
        }

        return true;

    }

    void orderedLoad(TreeNode* root, vector<int>& nums){
        if (root){
            if (root->left){
                orderedLoad(root->left, nums);
            }
            nums.push_back(root->val);
            if (root->right){
                orderedLoad(root->right, nums);
            }
        }
    }
};

int main() {
    Solution solution;
    TreeNode root(5);
    TreeNode l(3);
    TreeNode r(8);
    TreeNode ll(1);
    TreeNode lr(4);
    TreeNode rl(7);
    TreeNode rr(9);
    root.left = &l;
    root.right = &r;
    l.left = &ll;
    l.right = &lr;
    r.left = &rl;
    r.right = &rr;

    cout << solution.isValidBST(0) << endl;
    return 0;
}