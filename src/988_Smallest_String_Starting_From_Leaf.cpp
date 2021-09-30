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
    void solve(TreeNode* root, string result) {
        if (NULL == root->left && NULL == root->right) {
            string tmp = string(1, root->val+'a')+result;
            if (d_result == "") {
                d_result = tmp;
                return;
            }
            if (strcmp(d_result.c_str(), tmp.c_str()) > 0) {
                d_result = tmp;
            }
            return;
        }
        if (NULL != root->left) {
            solve(root->left, string(1, root->val+'a')+result);    
        }
        if (NULL != root->right) {
            solve(root->right, string(1, root->val+'a')+result);    
        }
    }
    
    string smallestFromLeaf(TreeNode* root) {
        string result;
        solve(root, result);
        return d_result;
    }
private:
    string d_result;
};
