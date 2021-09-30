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
    bool solve(TreeNode* root, int val) {
        if (NULL == root) {
            return true;
        }
        if (root->val != val) {
            return false;
        }
        if (!solve(root->left, val)) {
            return false;
        }
        if (!solve(root->right, val)) {
            return false;
        }
        return true;
    }
    
    bool isUnivalTree(TreeNode* root) {
        return solve(root, root->val);
    }
};
