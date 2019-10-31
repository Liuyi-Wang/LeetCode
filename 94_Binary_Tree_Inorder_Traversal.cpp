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
        stack<TreeNode*> s;
        while (root) {
            s.push(root);
            root = root->left;
        }
        while (!s.empty()) {
            root = s.top();
            s.pop();
            d_result.push_back(root->val);
            solve(root->right);
        }
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        solve(root);
        return d_result;
    }
    
private:
    vector<int> d_result;
};
