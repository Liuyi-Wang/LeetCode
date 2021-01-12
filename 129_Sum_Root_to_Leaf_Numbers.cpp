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
        if (NULL == root) {
            return 0;
        }
        int result = 0;
        int number = 0;
        recursion(root, result, number);
        return result;
    }
    
    void recursion(TreeNode* root, int& result, int& number) {
        if (NULL == root->left && NULL == root->right) {
            result += number*10+root->val;
            return;
        }
        number = number*10+root->val;
        if (root->left) {
            recursion(root->left, result, number);
        }
        if (root->right) {
            recursion(root->right, result, number);
        }
        number = (number-root->val)/10;
    }
};
