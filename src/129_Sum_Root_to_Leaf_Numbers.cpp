/**
 *  Time Complexity:
 *  O(n)
 *  Space Complexity:
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
    int sumNumbers(TreeNode* root) {
        d_result = 0;
        dfs(root, 0);
        return d_result;
    }
    
    void dfs(TreeNode* root, int sum) {
        sum = sum*10+root->val;
        if (root->left == NULL && root->right == NULL) {
            d_result += sum;
            return;
        }
        if (root->left) {
            dfs(root->left, sum);
        }
        if (root->right) {
            dfs(root->right, sum);
        }
    }
    
private:
    int d_result;
};
