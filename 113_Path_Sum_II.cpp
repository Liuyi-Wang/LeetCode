/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> result;
        vector<int> v;
        recursion(root, sum, result, v);
        return result;
    }
    
    void recursion(TreeNode* root, int sum, vector<vector<int>>& result, vector<int>& v) {
        if (NULL == root) {
            return;
        }
        if (NULL == root->left && NULL == root->right) {
            if (root->val == sum) {
                v.push_back(root->val);
                result.push_back(v);
                v.pop_back();
            }
            return;
        }
        v.push_back(root->val);
        recursion(root->left, sum-root->val, result, v);
        recursion(root->right, sum-root->val, result, v);
        v.pop_back();
    }
};
