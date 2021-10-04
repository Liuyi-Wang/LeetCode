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
    int deepestLeavesSum(TreeNode* root) {
        d_level = 0;
        d_sum = 0;
        solve(root, 0);
        return d_sum;
    }
    
    void solve(TreeNode* root, int level) {
        if (root == NULL) {
            return;
        }
        if (root->left == NULL && root->right == NULL) {
            if (level == d_level) {
                d_sum += root->val;
            } else if (level > d_level) {
                d_level = level;
                d_sum = root->val;
            }
            return;
        }
        solve(root->left, level+1);
        solve(root->right, level+1);
    }

private:
    int d_level;
    int d_sum;
};
