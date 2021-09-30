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
    int resolve(TreeNode* root, const int base) {
        if (NULL == root) {
            return 0;
        }
        int r_s = 0;
        if (root->right) {
            r_s = resolve(root->right, base);
        };
        root->val += r_s+base;
        int l_s = 0;
        if (root->left) {
            l_s = resolve(root->left, root->val);
        }
        return root->val+l_s-base;
    }
    
    TreeNode* bstToGst(TreeNode* root) {
        resolve(root, 0);
        return root;
    }
};
