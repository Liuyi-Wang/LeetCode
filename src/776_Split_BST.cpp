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
    vector<TreeNode*> splitBST(TreeNode* root, int V) {
        if (NULL == root) {
            return {NULL, NULL};
        }
        TreeNode *node = root;
        TreeNode *prev = NULL;
        while (node && node->val > V) {
            prev = node;
            node = node->left;
        }
        if (NULL == node) {
            return {NULL, root};
        }
        vector<TreeNode*> v = splitBST(node->right, V);
        if (prev) {
            node->right = v[0];
            prev->left = v[1];
            return {node, root};
        } else {
            node->right = v[0];
            return {node, v[1]};
        }
    }
};
