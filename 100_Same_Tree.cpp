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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (NULL == p && NULL == q) {
            return true;
        }
        if (NULL == p || NULL == q) {
            return false;
        } 
        if (p->val != q->val) {
            return false;
        }
        if (isSameTree(p->left, q->left) && isSameTree(p->right, q->right)) {
            return true;
        }
        return false;
    }
};
