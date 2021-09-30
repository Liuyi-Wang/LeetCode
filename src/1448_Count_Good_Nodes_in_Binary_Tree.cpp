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
    void solve(TreeNode *root, int greatest) {
        if (NULL == root) {
            return;
        }
        if (root->val >= greatest) {
            ++result;
            greatest = root->val;
        }
        solve(root->left, greatest);
        solve(root->right, greatest); 
    }
    
    int goodNodes(TreeNode* root) {
        result = 0;
        solve(root, INT_MIN);
        return result;
    }

private:
    int result;
};
