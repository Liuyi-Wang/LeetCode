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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        recursion(root, result, 0);
        return result;
    }
    
    void recursion(TreeNode* root, vector<int>& v, int index) {
        if (NULL == root) {
            return;
        }
        if (index == v.size()) {
            v.push_back(root->val);
        }
        recursion(root->right, v, index+1);
        recursion(root->left, v, index+1);
    }
};
