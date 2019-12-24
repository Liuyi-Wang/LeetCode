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
    int getMinimumDifference(TreeNode* root) {
        int result = INT_MAX;
        stack<TreeNode*> s;
        s.push(root);
        TreeNode *prev = NULL;
        while (!s.empty()) {
            root = s.top();
            s.pop();
            if (NULL == root->left && NULL == root->right) {
                if (NULL != prev) {
                    result = min(result, abs(prev->val-root->val));
                }
                prev = root;
            } else {
                if (root->right) {
                    s.push(root->right);
                    root->right = NULL;
                }
                s.push(root);
                if (root->left) {
                    s.push(root->left);
                    root->left = NULL;
                }
            }
        }
        return result;
    }
};
