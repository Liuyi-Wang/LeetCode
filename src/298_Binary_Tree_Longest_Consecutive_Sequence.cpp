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
        if (NULL == root->left && NULL == root->right) {
            d_result = max(d_result, 1);
            return 1;
        }
        int l = solve(root->left);
        int r = solve(root->right);
        int result = 1;
        if (NULL != root->left && root->left->val == root->val+1) {
            result = max(result, l+1);
        }
        if (NULL != root->right && root->right->val == root->val+1) {
            result = max(result, r+1);
        }
        d_result = max(d_result, result);
        return result;
    }
    
    int longestConsecutive(TreeNode* root) {
        d_result = 0;
        solve(root);
        return d_result;
    }
    
private:
    int d_result;
};
