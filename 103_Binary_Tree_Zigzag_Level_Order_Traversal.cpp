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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        if (root) {
            q.push(root);
        }
        vector<vector<int>> result;
        bool reverse = false;
        while (!q.empty()) {
            vector<int> level(q.size(), 0);
            for (int i = 0; i < level.size(); ++i) {
                root = q.front();
                q.pop();
                if (reverse) {
                    level[level.size()-1-i] = root->val;
                } else {
                    level[i] = root->val;
                }
                if (root->left) {
                    q.push(root->left);
                }
                if (root->right) {
                    q.push(root->right);
                }
            }
            result.push_back(level);
            reverse = !reverse;
        }
        return result;
    }
};
