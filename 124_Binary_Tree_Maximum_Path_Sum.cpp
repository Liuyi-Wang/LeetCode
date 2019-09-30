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
    int solve(TreeNode* root) {
        if (NULL == root) {
            return 0;
        }
        int l = solve(root->left);
        int r = solve(root->right);
        int sum = root->val+max(0, l)+max(0, r);
        d_result = max(d_result, sum);
        return root->val+max(max(r, l), 0);
    }
    
    int maxPathSum(TreeNode* root) {
        d_result = root->val;
        solve(root);
        return d_result;
    }
private:
    int d_result;
};
