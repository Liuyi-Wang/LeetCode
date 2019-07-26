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
    void solve(TreeNode* root, const int& upMax, const int& upMin, int& downMax, int& downMin) {
        d_result = max(d_result, abs(root->val-upMax));
        d_result = max(d_result, abs(root->val-upMin));
        downMax = root->val;
        downMin = root->val;
        if (NULL != root->left) {
            int lMax = 0, lMin = 0;
            solve(root->left, root->val, root->val, lMax, lMin);
            d_result = max(d_result, abs(root->val-lMax));
            d_result = max(d_result, abs(root->val-lMin));
            downMax = max(downMax, lMax);
            downMin = min(downMin, lMin);
        }
        if (NULL != root->right) {
            int rMax = 0, rMin = 0;
            solve(root->right, root->val, root->val, rMax, rMin);
            d_result = max(d_result, abs(root->val-rMax));
            d_result = max(d_result, abs(root->val-rMin));
            downMax = max(downMax, rMax);
            downMin = min(downMin, rMin);
        }
    }
    
    int maxAncestorDiff(TreeNode* root) {
        d_result = INT_MIN;
        if (NULL != root->left) {
            int lMax = 0, lMin = 0;
            solve(root->left, root->val, root->val, lMax, lMin);
            d_result = max(d_result, abs(root->val-lMax));
            d_result = max(d_result, abs(root->val-lMin));
        }
        if (NULL != root->right) {
            int rMax = 0, rMin = 0;
            solve(root->right, root->val, root->val, rMax, rMin);
            d_result = max(d_result, abs(root->val-rMax));
            d_result = max(d_result, abs(root->val-rMin));
        }
        return d_result;
    }
private:
    int d_result;
};
