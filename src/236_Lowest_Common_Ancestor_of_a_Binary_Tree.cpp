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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (NULL == root) {
            return NULL;
        }
        if (root->val == p->val || root->val == q->val) {
            return root;
        }
        TreeNode *l = lowestCommonAncestor(root->left, p, q);
        if (NULL != l && l->val != p->val && l->val != q->val) {
            return l;
        }
        TreeNode *r = lowestCommonAncestor(root->right, p, q);
        if (NULL != r && r->val != p->val && r->val != q->val) {
            return r;
        }
        if (NULL == l) {
            return r;
        }
        if (NULL == r) {
            return l;
        }
        return root;
    }
};
