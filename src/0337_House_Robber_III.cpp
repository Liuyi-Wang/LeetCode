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
    int rob(TreeNode* root) {
        pair<int, int> p = sol1(root);
        return max(p.first, p.second);
    }
    
    pair<int, int> sol1(TreeNode* root) {
        pair<int, int> pl = {0, 0};
        if (root->left) {
            pl = sol1(root->left);
        }
        pair<int, int> pr = {0, 0};
        if (root->right) {
            pr = sol1(root->right);
        }
        pair<int, int> p;
        p.first = root->val+pl.second+pr.second;
        p.second = max(pl.first, pl.second)+max(pr.first, pr.second);
        return p;
    }
};
