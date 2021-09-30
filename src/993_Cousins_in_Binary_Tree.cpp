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
    void solve(TreeNode* root, const int& x, const int& y, int depth, int parent) {
        if (NULL == root) {
            return;
        }
        if (x == root->val) {
            d_x_p = parent;
            d_x_d = depth+1;
        }
        if (y == root->val) {
            d_y_p = parent;
            d_y_d = depth+1;
        }
        if (-1 != d_x_d && -1 != d_y_d) {
            return;
        }
        solve(root->left, x, y, depth+1, root->val);
        if (-1 != d_x_d && -1 != d_y_d) {
            return;
        }
        solve(root->right, x, y, depth+1, root->val);
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        if (x < 1 || x > 100 || y < 1 || y > 100) {
            return false;
        }
        d_x_p = -1;
        d_y_p = -1;
        d_x_d = -1;
        d_y_d = -1;
        solve(root->left, x, y, 0, root->val); 
        if (-1 == d_x_d || -1 == d_y_d) {
            solve(root->right, x, y, 0, root->val); 
        }
        if (-1 == d_x_d || -1 == d_y_d) {
            return false;
        }
        if (d_x_d == d_y_d && d_x_p != d_y_p) {
            return true;
        }
        return false;
    }
private:
    int d_x_p;
    int d_y_p;
    int d_x_d;
    int d_y_d;
};
