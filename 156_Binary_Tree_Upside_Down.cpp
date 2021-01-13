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
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if (NULL == root) {
            return NULL;
        }
        if (NULL == root->left) {
            return root;
        }
        TreeNode* node = upsideDownBinaryTree(root->left);
        TreeNode* l = root->left;
        TreeNode* r = root->right;
        l->left = r;
        l->right = root;
        root->left = NULL;
        root->right = NULL;
        return node;
    }
};
