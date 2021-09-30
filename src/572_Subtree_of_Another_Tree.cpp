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
    bool solve(TreeNode* s, TreeNode* t) {
        if (NULL == s && NULL == t) {
            return true;
        }   
        if (NULL == s || NULL == t) {
            return false;
        }
        if (s->val != t->val) {
            return false;
        }
        return solve(s->left, t->left) && solve(s->right, t->right);
    }
    
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (NULL == t) {
            return true;
        }
        if (NULL == s) {
            return false;
        }
        return solve(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t);
    }
};
