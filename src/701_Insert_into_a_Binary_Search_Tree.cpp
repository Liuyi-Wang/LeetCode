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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (NULL == root) {
            return new TreeNode(val);
        }
        if (root->val > val) {
            root->left = insertIntoBST(root->left, val);
            return root;
        }
        root->right = insertIntoBST(root->right, val);
        return root;
    }
};
