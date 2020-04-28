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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (NULL == root) {
            return root;
        }
        if (root->val > key) {
            root->left = deleteNode(root->left, key);
            return root;
        }
        if (root->val < key) {
            root->right = deleteNode(root->right, key);
            return root;
        }
        if (NULL == root->left && NULL == root->right) {
            return NULL;
        }
        if (NULL == root->left) {
            return root->right;
        }
        if (NULL == root->right) {
            return root->left;
        }
        TreeNode* node = root->right;
        while (node->left) {
            node = node->left;
        }
        root->val = node->val;
        root->right = deleteNode(root->right, node->val);
        return root;
    }
};
