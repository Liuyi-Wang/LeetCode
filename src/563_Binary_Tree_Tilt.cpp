/**
 *  Time:
 *  O(n)
 *  Space:
 *  O(1)
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
    int result;
public:
    int findTilt(TreeNode* root) {
        sum(root);
        return result;
    }
    
    int sum(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int l = sum(root->left);
        int r = sum(root->right);
        result += abs(l-r);
        return l+r+root->val;
    }
};
