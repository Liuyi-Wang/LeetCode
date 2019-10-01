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
    bool solve(TreeNode* root, int& h, bool& isFull) {
        if (NULL == root) {
            isFull = true;
            return true;
        }
        int l = 0, r = 0;
        bool lf = false, rf = false;
        if (!solve(root->left, l, lf)) {
            return false;
        }
        if (!solve(root->right, r, rf)) {
            return false;
        }
        if (lf && rf && l == r) {
            h = l+1;
            isFull = true;
            return true;
        }
        if (rf && l == r+1) {
            h = l+1;
            isFull = false;
            return true;
        }
        if (lf && !rf && l == r) {
            h = l+1;
            isFull = false;
            return true;
        }
        return false;
    }
        
    bool isCompleteTree(TreeNode* root) {
        int h = 0;
        bool isFull = false;
        return solve(root, h, isFull);
    }
};
