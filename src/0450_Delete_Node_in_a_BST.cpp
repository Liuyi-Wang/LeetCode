/**
 *  Time:
 *  O(logn)
 *  Space:
 *  O(logn)
 */
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL) {
            return NULL;
        }
        if (root->val < key) {
            root->right = deleteNode(root->right, key);
            return root;
        }
        if (root->val > key) {
            root->left = deleteNode(root->left, key);
            return root;
        }
        if (root->left == NULL && root->right == NULL) {
            return NULL;
        }
        if (root->left == NULL && root->right) {
            return root->right;
        }
        if (root->left && root->right == NULL) {
            return root->left;
        }
        TreeNode* node = root->right;
        while (node && node->left) {
            node = node->left;
        }
        root->val = node->val;
        root->right = deleteNode(root->right, node->val);
        return root;
    }
};
