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
    bool solve(TreeNode *r1, TreeNode *r2) {
        if (NULL == r1 && NULL == r2) {
            return true;
        }
        if (NULL == r1 || NULL == r2 || r1->val != r2->val) {
            return false;
        }
        return solve(r1->left, r2->right) && solve(r1->right, r2->left);
    }
    
    bool isSymmetric(TreeNode* root) {
        if (NULL == root) {
            return true;
        }
        return solve(root->left, root->right);
    }
};
