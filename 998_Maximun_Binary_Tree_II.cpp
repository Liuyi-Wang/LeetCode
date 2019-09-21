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
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        TreeNode* v = new TreeNode(val);
        if (val > root->val) {
            v->left = root;
            return v;
        }
        TreeNode* parent = root;
        TreeNode* node = root->right;
        while (NULL != node) {
            if (node->val < val) {
                v->left = node;
                parent->right = v;
                return root;
            } else {
                parent = node;
                node = node->right;
            }
        }
        if (NULL == node) {
            parent->right = v;
        }
        return root;
    }
};
