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
    void solve(TreeNode* root, TreeNode* &head, TreeNode* &tail) {
        if (root->left && root->right) {
            TreeNode* lh = NULL, * lt = NULL;
            solve(root->left, lh, lt);
            TreeNode* rh = NULL, * rt = NULL;
            solve(root->right, rh, rt);
            lt->right = root;
            root->left = NULL;
            root->right = rh;
            head = lh;
            tail = rt;
            return;
        }
        if (root->left) {
            TreeNode* lh = NULL, * lt = NULL;
            solve(root->left, lh, lt);
            lt->right = root;
            root->left = NULL;
            root->right = NULL;
            head = lh;
            tail = root;
            return;
        }
        if (root->right) {
            TreeNode* rh = NULL, * rt = NULL;
            solve(root->right, rh, rt);
            root->left = NULL;
            root->right = rh;
            head = root;
            tail = rt;
            return;
        }
        head = root;
        tail = root;
        return;
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* head = NULL, * tail = NULL;
        solve(root, head, tail);
        return head;
    }
};
