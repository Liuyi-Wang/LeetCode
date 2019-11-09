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
    void solve(TreeNode* root, int &minV, int &maxV) {
        if (NULL == root) {
            return;
        }
        if (NULL == root->left && NULL == root->right) {
            minV = root->val;
            maxV = root->val;
            return;
        }
        if (NULL != root->left && NULL == root->right) {
            int lminV = 0, lmaxV = 0;
            solve(root->left, lminV, lmaxV);
            d_result = min(d_result, abs(lmaxV-root->val));
            maxV = root->val;
            minV = lminV;
            return;
        }
        if (NULL == root->left && NULL != root->right) {
            int rminV = 0, rmaxV = 0;
            solve(root->right, rminV, rmaxV);
            d_result = min(d_result, abs(rminV-root->val));
            minV = root->val;
            maxV = rmaxV;
            return;
        }
        int lminV = 0, lmaxV = 0;
        solve(root->left, lminV, lmaxV);
        d_result = min(d_result, abs(lmaxV-root->val));
        int rminV = 0, rmaxV = 0;
        solve(root->right, rminV, rmaxV);
        d_result = min(d_result, abs(rminV-root->val));
        maxV = rmaxV;
        minV = lminV;
    }
    
    int minDiffInBST(TreeNode* root) {
        d_result = INT_MAX;
        int minV = 0, maxV = 0;
        solve(root, minV, maxV);
        return d_result;
    }
    
private:
    int d_result;
};
