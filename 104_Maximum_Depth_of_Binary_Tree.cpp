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
    int depth(TreeNode* root, int d) {
        if (NULL == root) {
            return d;
        }
        int l = depth(root->left, d+1);
        int r = depth(root->right, d+1);
        return max(l, r);
    }
    
    int maxDepth(TreeNode* root) {
        return depth(root, 0);
    }
};
