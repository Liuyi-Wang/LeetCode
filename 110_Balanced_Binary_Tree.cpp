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
    bool solve(TreeNode* root, int &h) {
        if (NULL == root) {
            h = 0;
            return true;
        }
        int lh;
        bool l = solve(root->left, lh);
        if (!l) {
            return false;
        }
        int rh;
        bool r = solve(root->right, rh);
        if (!r) {
            return false;
        }
        if (abs(lh-rh) > 1) {
            return false;
        }
        h = max(lh, rh)+1;
        return true;
    }
    
    bool isBalanced(TreeNode* root) {
        int h;
        return solve(root, h);
    }
};
