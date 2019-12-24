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
        d_result = max(d_result, l+r+1);
        return max(l, r)+1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        if (NULL == root) {
            return 0;
        }
        d_result = 0;
        solve(root);
        return d_result-1;
    }
    
private:
    int d_result;
};
