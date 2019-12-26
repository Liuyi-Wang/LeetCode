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
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if (NULL == root) {
            return NULL;
        }
        stack<TreeNode*> s;
        while (root) {
            s.push(root);
            root = root->left;
        }
        root = s.top();
        s.pop();
        TreeNode *node = root;
        while (!s.empty()) {
            node->left = s.top()->right;
            node->right = s.top();
            s.top()->left = NULL;
            s.top()->right = NULL;
            s.pop();
            node = node->right;
        }
        return root;
    }
};
