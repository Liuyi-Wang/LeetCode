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
    void solve(TreeNode* root, int sum) {
        if (NULL == root->left && NULL == root->right) {
            d_result += sum*10+root->val;
            return;
        }
        if (root->left) {
            solve(root->left, sum*10+root->val);
        }
        if (root->right) {
            solve(root->right, sum*10+root->val);
        }
    }
    
    int sumNumbers(TreeNode* root) {
        if (NULL == root) {
            return 0;
        }
        d_result = 0;
        solve(root, 0);
        return d_result;
    }
    
private:
    int d_result;
};
