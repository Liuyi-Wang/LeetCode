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
    int getHeight(TreeNode* root) {
        if (NULL == root) {
            return 0;
        }
        return getHeight(root->left)+1;
    }
    
    int countNodes(TreeNode* root) {
        if (NULL == root) {
            return 0;
        }
        int lh = getHeight(root->left);
        int rh = getHeight(root->right);
        if (lh == rh) {
            return (1<<lh)-1+countNodes(root->right)+1;
        }
        return (1<<rh)-1+countNodes(root->left)+1;
    }
};
