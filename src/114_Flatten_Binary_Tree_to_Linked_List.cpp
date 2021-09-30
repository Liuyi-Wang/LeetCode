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
    void flatten(TreeNode* root) {
        while (root) {
            if (root->left && NULL == root->right) {
                root->right = root->left;
                root->left = NULL;
            } else if (root->left) {
                TreeNode* leftTail = root->left;
                while (leftTail->right) {
                    leftTail = leftTail->right;
                }
                leftTail->right = root->right;
                root->right = root->left;
                root->left = NULL;
            }
            root = root->right;
        }
    }
    
    /*
    void flatten(TreeNode* root) {
        if (NULL == root) {
            return;
        }
        TreeNode* tail = NULL;
        recursion(root, tail);
    }
    
    void recursion(TreeNode* root, TreeNode* &tail) {
        TreeNode* l = root->left;
        TreeNode* r = root->right;
        if (l && r) {
            TreeNode* lt = NULL;
            recursion(l, lt);
            TreeNode* rt = NULL;
            recursion(r, rt);
            root->left = NULL;
            root->right = l;
            lt->right = r;
            tail = rt;
        } else if (l) {
            TreeNode* lt = NULL;
            recursion(l, lt);
            root->left = NULL;
            root->right = l;
            tail = lt;
        } else if (r) {
            TreeNode* rt = NULL;
            recursion(r, rt);
            tail = rt;
        } else {
            tail = root;
        }
    }*/
};
