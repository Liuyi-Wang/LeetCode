/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool solve(TreeNode* root) {
        if (NULL == root) {
            return false;
        }
        bool l = solve(root->left);
        if (!l) {
            root->left = NULL;
        }
        bool r = solve(root->right);
        if (!r) {
            root->right = NULL;
        }
        if (l || r) {
            return true;
        }
        return root->val==1;
    }
    
    TreeNode* pruneTree(TreeNode* root) {
        if (!solve(root) && 0 == root->val) {
            return NULL;
        }
        return root;
    }
};
