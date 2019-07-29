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
    void solve(TreeNode* root, int sum) {
        if (NULL == root->left && NULL == root->right) {
            d_result += root->val+sum*2;
            return;
        }
        if (NULL != root->left) {
            solve(root->left, root->val+sum*2);
        }        
        if (NULL != root->right) {
            solve(root->right, root->val+sum*2);
        }        
    }
    
    int sumRootToLeaf(TreeNode* root) {
        if (NULL == root) {
            return 0;
        }
        d_result = 0;
        solve(root, 0);
        return d_result;
    }
    
private:
    int d_result;
};
