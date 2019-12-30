static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

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
        if (NULL == root->left && NULL == root->right) {
            return 1;
        }
        if (NULL == root->left && root->val == root->right->val) {
            d_result = max(d_result, r+1);
            return r+1;
        } else if (NULL == root->left) {
            return 1;
        }
        if (NULL == root->right && root->val == root->left->val) {
            d_result = max(d_result, l+1);
            return l+1;
        } else if (NULL == root->right) {
            return 1;    
        }
        if (root->val == root->left->val && root->val == root->right->val) {
            d_result = max(d_result, l+r+1);
            return max(l, r)+1;
        }
        if (root->val == root->left->val) {
            d_result = max(d_result, l+1);
            return l+1;
        }
        if (root->val == root->right->val) {
            d_result = max(d_result, r+1);
            return r+1;
        }
        return 1;
    }
    
    int longestUnivaluePath(TreeNode* root) {
        d_result = 1;
        solve(root);
        return d_result-1;
    }
    
private:
    int d_result;
};
