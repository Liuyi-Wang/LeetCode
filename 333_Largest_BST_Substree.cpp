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
    int solve(TreeNode* root, int &min_n, int &max_n) {
        if (NULL == root) {
            min_n = INT_MAX;
            max_n = INT_MIN;
            return 0;
        }
        int min_l, max_l, min_r, max_r;
        int l = solve(root->left, min_l, max_l);
        int r = solve(root->right, min_r, max_r);
        if (l < 0 || r < 0) {
            return -1;
        }
        if (max_l >= root->val || min_r <= root->val) {
            return -1;
        }
        d_result = max(d_result, l+r+1);
        min_n = min(min_l, root->val);
        max_n = max(max_r, root->val);
        return l+r+1;
    }
    
    int largestBSTSubtree(TreeNode* root) {
        d_result = 0;
        int mi, ma;
        solve(root, mi, ma);
        return d_result;
    }
    
private:
    int d_result;
};
