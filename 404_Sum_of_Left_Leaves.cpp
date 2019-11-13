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
    void solve(TreeNode* root, bool left) {
        if (NULL == root) {
            return;
        }
        if (NULL == root->left && NULL == root->right) {
            if (left) {
                d_result += root->val;
            }
            return;
        }
        if (root->left) {
            solve(root->left, true);
        }
        if (root->right) {
            solve(root->right, false);
        }
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        d_result = 0;
        solve(root, false);
        return d_result;
    }
    
private:
    int d_result;
};
