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
public:
    int sumOfLeftLeaves(TreeNode* root) {
        d_result = 0;
        dfs(root->left, true);
        dfs(root->right, false);
        return d_result;
    }
    
    void dfs(TreeNode* root, bool left) {
        if (!root) {
            return;
        }
        if (root->left == NULL && root->right == NULL && left) {
            d_result += root->val;
            return;
        }
        dfs(root->left, true);
        dfs(root->right, false);
    }
    
private:
    int d_result;
};
