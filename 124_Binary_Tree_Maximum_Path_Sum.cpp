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
    int maxPathSum(TreeNode* root) {
        int path = 0;
        return recursion(root, path);
    }
    
    int recursion(TreeNode* root, int& path) {
        if (NULL == root) {
            return INT_MIN;
        }
        int lp = 0;
        int lps = recursion(root->left, lp);
        int rp = 0;
        int rps = recursion(root->right, rp);
        path = max(0, max(lp, rp))+root->val;
        return max(root->val+max(lp, 0)+max(rp, 0), max(lps, rps));
    }
};
