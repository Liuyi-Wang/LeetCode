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
    int sumRootToLeaf(TreeNode* root) {
        result = 0;
        dfs(root, 0);
        return result;
    }
    
    void dfs(TreeNode* root, int sum) {
        sum = sum*2+root->val;
        if (root->left == NULL && root->right == NULL) {
            result += sum;
            return;
        }
        if (root->left) {
            dfs(root->left, sum);
        }
        if (root->right) {
            dfs(root->right, sum);
        }
    }
};
