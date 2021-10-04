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
    int M = 1e9 + 7;
    int maxProduct(TreeNode* root) {
        long long s = sum(root);
        long long subsum = 0;
        long long result = dfs(root, s, subsum);
        return result%M;
    }
    
    long long sum(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        long long ls = sum(root->left);
        long long rs = sum(root->right);
        return root->val+ls+rs;
    }
    
    long long dfs(TreeNode* root, const long long& sum, long long& subsum) {
        if (root == NULL) {
            return 0;
        }
        long long lsubsum = 0, rsubsum = 0;
        long long lp = dfs(root->left, sum, lsubsum);
        long long rp = dfs(root->right, sum, rsubsum);
        subsum = root->val+lsubsum+rsubsum;
        long long p = subsum*(sum-subsum);
        return max(max(p, lp), rp);
    }
};
