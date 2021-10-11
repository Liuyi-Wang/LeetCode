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
    int diameterOfBinaryTree(TreeNode* root) {
        int l = 0;
        return solve(root, l);
    }
    
    int solve(TreeNode* root, int &len) {
        if (root == NULL) {
            return 0;
        }
        if (root->left == NULL && root->right == NULL) {
            return 0;
        }
        int l = 0, r = 0;
        int l_r = solve(root->left, l);
        int r_r = solve(root->right, r);
        len = 1+max(l, r);
        int result = l+r+(root->left?1:0)+(root->right?1:0);
        return max(r_r, max(result, l_r));
    }
};
