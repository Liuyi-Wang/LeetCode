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
    void solve(TreeNode* root) {
        if (NULL == root) {
            return;
        }
        if (root->val <= d_result && root->val > d_min) {
            d_find = true;
            d_result = root->val;
        }
        solve(root->left);
        solve(root->right);
    }
    
    int findSecondMinimumValue(TreeNode* root) {
        if (NULL == root) {
            return -1;
        }
        d_min = root->val;
        d_result = INT_MAX;
        d_find = false;
        solve(root);
        if (!d_find) {
            return -1;
        }
        return d_result;
    }
    
private:
    int d_min;
    int d_result;
    bool d_find;
};
