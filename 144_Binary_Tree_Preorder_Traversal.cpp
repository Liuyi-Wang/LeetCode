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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        TreeNode* it = root;
        stack<TreeNode*> s;
        while (it || !s.empty()) {
            while (it) {
                result.push_back(it->val);
                s.push(it);
                it = it->left;
            }
            it = s.top();
            s.pop();
            it = it->right;
        }
        return result;
    }
};
