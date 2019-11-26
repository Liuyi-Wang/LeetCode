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
    TreeNode *solve(TreeNode *root) {
        if (root->left && root->right) {
            TreeNode *lt = solve(root->left);
            TreeNode *rt = solve(root->right);
            lt->right = root->right;
            root->right = root->left;
            root->left = NULL;
            return rt;
        } else if (root->left) {
            TreeNode *lt = solve(root->left);
            root->right = root->left;
            root->left = NULL;
            return lt;
        } else if (root->right) {
            TreeNode *rt = solve(root->right);
            return rt;
        }
        return root;
    }
    
    void flatten(TreeNode* root) {
        if (NULL == root) {
            return;
        }
        solve(root);
    }
};
