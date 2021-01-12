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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        if (NULL == root) {
            return result;
        }
        stack<TreeNode*> stk;
        TreeNode* it = root;
        while (!stk.empty() || it) {
            while (it) {
                stk.push(it);
                it = it->left;
            } 
            TreeNode* node = stk.top();
            stk.pop();
            result.push_back(node->val);
            it = node->right;
        }
        return result;
    }
};
