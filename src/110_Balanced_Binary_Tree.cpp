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
    bool isBalanced(TreeNode* root) {
        int height = 0;
        return recursion(root, height);
    }
    
    bool recursion(TreeNode* root, int &height) {
        if (NULL == root) {
            height = 0;
            return true;
        }
        int lh = 0;
        if (!recursion(root->left, lh)) {
            return false;
        }
        int rh = 0;
        if (!recursion(root->right, rh)) {
            return false;
        }
        if (abs(lh-rh) > 1) {
            return false;
        }
        height = max(lh, rh) + 1;
        return true;
    }
};
