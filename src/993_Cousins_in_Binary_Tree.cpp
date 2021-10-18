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
    bool isCousins(TreeNode* root, int x, int y) {
        d_dx = -1;
        d_dy = -1;
        if (!sol(root, x, y, 0)) {
            return false;
        }
        return d_dx == d_dy;
    }
    
    bool sol(TreeNode* root, int x, int y, int d) {
        if (root == NULL) {
            return true;
        }
        if (root->left && root->right) {
            if (root->left->val == x && root->right->val == y) {
                return false;
            } else if (root->left->val == y && root->right->val == x) {
                return false;
            }
        }
        if (root->val == x) {
            d_dx = d;
        } else if (root->val == y) {
            d_dy = d;
        }
        if (d_dx == -1 || d_dy == -1) {
            if (!sol(root->left, x, y, d+1)) {
                return false;
            }
            if (!sol(root->right, x, y, d+1)) {
                return false;
            }
        }
        return true;
    }
    
private:
    int d_dx;
    int d_dy;
};
