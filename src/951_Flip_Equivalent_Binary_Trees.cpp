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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if (NULL == root1 && NULL == root2) {
            return true;
        }
        if (NULL == root1 || NULL == root2) {
            return false;
        }
        if (root1->val != root2->val) {
            return false;
        }
        bool l = flipEquiv(root1->left, root2->left);
        bool r = flipEquiv(root1->right, root2->right);
        if (l && r) {
            return true;
        }
        l = flipEquiv(root1->left, root2->right);
        r = flipEquiv(root1->right, root2->left);
        if (l && r) {
            return true;
        }
        return false;
    }
};
