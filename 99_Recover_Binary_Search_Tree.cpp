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
    void recoverTree(TreeNode* root) {
        TreeNode* prev = NULL;
        TreeNode* first = NULL;
        TreeNode* second = NULL;
        while (root) {
            if (root->left) {
                TreeNode* node = root->left;
                while (node->right && node->right != root) {
                    node = node->right;
                }
                if (node->right) {
                    node->right = NULL;
                } else {
                    node->right = root;
                    root = root->left;
                    continue;
                }
            }
            if (prev && prev->val > root->val) {
                if (NULL == first) {
                    first = prev;
                }
                second = root;
            } 
            prev = root;
            root = root->right;
        }
        swap(first->val, second->val);
    }
};
