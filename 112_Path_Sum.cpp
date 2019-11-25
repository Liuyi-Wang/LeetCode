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
    bool solve(TreeNode *root, const int &sum, int s) {
        if (NULL == root->left && NULL == root->right) {
            if (s+root->val == sum) {
                return true;
            }
            return false;
        }
        if (root->left && solve(root->left, sum, s+root->val)) {
            return true;
        }
        if (root->right && solve(root->right, sum, s+root->val)) {
            return true;
        }
        return false;
    }
    
    bool hasPathSum(TreeNode* root, int sum) {
        if (NULL == root) {
            return false;
        }
        return solve(root, sum, 0);
    }
};
