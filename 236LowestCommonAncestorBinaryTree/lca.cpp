#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

//Definition for a binary tree node.
struct TreeNode {    
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // load up all values from root to node in a vector
        vector<TreeNode*> ppath, qpath;
        ppath.push_back(root);
        qpath.push_back(root);
        loadPath(root, p, ppath);
        loadPath(root, q, qpath);

        // check if top of ppath is in qpath, pop if not
        while(!ppath.empty()){
            if (find(qpath.begin(), qpath.end(), ppath.back()) != qpath.end()){
                // the first top of ppath that exists in qpath is the LCA
                return ppath.back();
            } else {
                ppath.pop_back();
            }
        }
    }
private:
    bool loadPath(TreeNode* root, TreeNode* node, vector<TreeNode*>& path){
        // DFS to find node in order to find path
        // check if top is node. if so, return

        if (path.back() == node){
            return true;
        } else if (path.back()){
            TreeNode* temp = path.back();
            path.push_back(temp->left);
            if (loadPath(root, node, path)){
                return true;
            } else {
                path.pop_back();
            }
            path.push_back(temp->right);
            if (loadPath(root, node, path)){
                return true;
            } else {
                path.pop_back();
            }
        } else {
            return false;
        }
    }

};

int main(){
    Solution solution;
    TreeNode five(5);
    TreeNode three(3);
    TreeNode one(1);
    TreeNode two(2);
    five.left = &three;
    five.right = &one;
    three.left = &two;

    cout << solution.lowestCommonAncestor(&five, &three, &one)->val << endl;
    return 0;
}
