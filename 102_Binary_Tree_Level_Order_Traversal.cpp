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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        if (root) {
            q.push(root);
        }
        vector<vector<int>> result;
        while (!q.empty()) {
            vector<int> level(q.size(), 0);
            for (int i = 0; i < level.size(); ++i) {
                root = q.front();
                q.pop();
                level[i] = root->val;
                if (root->left) {
                    q.push(root->left);
                }
                if (root->right) {
                    q.push(root->right);
                }
            }
            result.push_back(level);
        }
        return result;
    }
};
