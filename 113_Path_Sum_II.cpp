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
    void solve(TreeNode *root, const int &sum, int s, vector<int> &v) {
        v.push_back(root->val);
        s += root->val;
        if (NULL == root->left && NULL == root->right) {
            if (s == sum) {
                d_result.push_back(v);
            }
            v.pop_back();
            return;
        }
        if (root->left) {
            solve(root->left, sum, s, v);
        }
        if (root->right) {
            solve(root->right, sum, s, v);
        }
        v.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if (NULL == root) {
            return d_result;
        }
        vector<int> v;
        solve(root, sum, 0, v);
        return d_result;
    }
    
private:
    vector<vector<int>> d_result;
};
