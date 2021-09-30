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
    bool solve(TreeNode *root) {
        if (NULL == root->left && NULL == root->right) {
            ++d_result;
            return true;
        }
        if (NULL == root->left && root->right) {
            bool r = solve(root->right);
            if (root->val != root->right->val) {
                return false;
            }
            if (r) {
                ++d_result;
            }
            return r;
        }
        if (root->left && NULL == root->right) {
            bool l = solve(root->left);
            if (root->val != root->left->val) {
                return false;
            }
            if (l) {
                ++d_result;
            }
            return l;
        }
        bool r = solve(root->right);
        bool l = solve(root->left);
        if (root->val != root->right->val) {
            return false;
        }
        if (root->val != root->left->val) {
            return false;
        }
        if (l && r) {
            ++d_result;
        }
        return l && r;
    }
    
    int countUnivalSubtrees(TreeNode* root) {
        if (NULL == root) {
            return 0;
        }    
        d_result = 0;
        solve(root);
        return d_result;
    }
    
private:
    int d_result;
};
