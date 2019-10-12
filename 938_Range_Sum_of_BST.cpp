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
    int rangeSumBST(TreeNode* root, int L, int R) {
        if (NULL == root) {
            return 0;
        }
        if (root->val >= L && root->val <= R) {
            int l = rangeSumBST(root->left, L, R);
            int r = rangeSumBST(root->right, L, R);
            return root->val+l+r;   
        } else if (root->val < L) {
            return rangeSumBST(root->right, L, R);
        } else {
            return rangeSumBST(root->left, L, R);
        }
    }
};
