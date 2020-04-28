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
    void solve(TreeNode* root, int &inc, int &dec) {
        if (NULL == root) {
            inc = 0;
            dec = 0;
            return;
        }
        int linc = 1, ldec = 1;
        if (root->left) {
            solve(root->left, linc, ldec);
            if (root->left->val == root->val+1) {
                inc = max(inc, linc+1);
            }
            if (root->left->val == root->val-1) {
                dec = max(dec, ldec+1);
            }
        }
        int rinc = 1, rdec = 1;
        if (root->right) {
            solve(root->right, rinc, rdec);
            if (root->right->val == root->val+1) {
                inc = max(inc, rinc+1);
            }
            if (root->right->val == root->val-1) {
                dec = max(dec, rdec+1);
            }
        }
        if (root->left && root->right) {
            if (root->left->val == root->val+1 && root->right->val == root->val-1) {
                result = max(result, linc+rdec+1);
            }
            if (root->left->val == root->val-1 && root->right->val == root->val+1) {
                result = max(result, rinc+ldec+1);
            }
        }
        result = max(result, inc);
        result = max(result, dec);
    }
    
    int longestConsecutive(TreeNode* root) {
        result = 0;
        int inc = 1, dec = 1;
        solve(root, inc, dec);
        return result;
    }
 
private:
    int result;
};
