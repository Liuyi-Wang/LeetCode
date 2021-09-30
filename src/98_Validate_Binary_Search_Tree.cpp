/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if (NULL == root) {
            return true;
        }
        int min_val = root->val, max_val = root->val;
        return recursion(root, min_val, max_val);
    }
    
    bool recursion(TreeNode* root, int& min_val, int& max_val) {
        int lmin = root->val;
        int lmax = root->val;
        int rmin = root->val;
        int rmax = root->val;
        if (root->left) {
            if (!recursion(root->left, lmin, lmax)) {
                return false;
            }
            if (lmax >= root->val) {
                return false;
            }
        }
        if (root->right) {
            if (!recursion(root->right, rmin, rmax)) {
                return false;
            }
            if (rmin <= root->val) {
                return false;
            }
        }
        min_val = lmin;
        max_val = rmax;
        return true;
    }
};
