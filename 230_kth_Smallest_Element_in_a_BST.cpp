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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> s;
        s.push(root);
        int count = 0;
        while (!s.empty()) {
            root = s.top();
            s.pop();
            if (NULL == root->left && NULL == root->right) {
                ++count;
                if (count == k) {
                    return root->val;
                }
                continue;
            }
            TreeNode *l = root->left;
            TreeNode *r = root->right;
            root->left = NULL;
            root->right = NULL;
            if (r) {
                s.push(r);
            }
            s.push(root);
            if (l) {
                s.push(l);
            }
        }
        return 0;
    }
};
