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
    int solve(TreeNode* root) {
        if (NULL == root) {
            return -1;
        }
        int level = 1+max(solve(root->left), solve(root->right));
        if (level+1 > d_result.size()) {
            d_result.resize(level+1);
        }
        d_result[level].push_back(root->val);
        return level;
    }
    
    vector<vector<int>> findLeaves(TreeNode* root) {
        solve(root);
        return d_result;
    }
    
private:
    vector<vector<int>> d_result;
};
