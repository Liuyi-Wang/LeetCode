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
    int countNodes(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int l = 0;
        TreeNode* node = root->left;
        while (node) {
            ++l;
            node = node->left;
        }
        int r = 0;
        node = root->right;
        while (node) {
            ++r;
            node = node->left;
        }
        if (l == r) {
            return pow(2, l)+countNodes(root->right);
        }
        return countNodes(root->left)+pow(2, r);
    }
};
