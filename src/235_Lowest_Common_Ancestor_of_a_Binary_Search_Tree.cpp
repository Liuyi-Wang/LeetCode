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
    /*   
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root->val == p->val || root->val == q->val) {
            return root;
        }
        if ((root->val > p->val && root->val < q->val) || (root->val < p->val && root->val > q->val)) {
            return root;
        }
        if (root->val < p->val) {
            return lowestCommonAncestor(root->right, p, q);
        }
        return lowestCommonAncestor(root->left, p, q);
    }
    */
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (true) {
            if (root->val < p->val && root->val < q->val) {
                root = root->right;
                continue;
            }
            if (root->val > p->val && root->val > q->val) {
                root = root->left;
                continue;
            }
            return root;
        }
    }
};
