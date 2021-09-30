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
    void solve(TreeNode *root) {
        if (NULL == root->left && NULL == root->right) {
            ++count[root->val];
            if (count[root->val]%2 == 0) {
                --odd;
                if (1 >= odd) {
                    ++result;
                }
                ++odd;
            } else {
                ++odd;
                if (1 >= odd) {
                    ++result;
                }
                --odd;
            }
            --count[root->val];
            ++i;
            return;
        }
        ++count[root->val];
        if (count[root->val]%2 == 0) {
            --odd;
            if (root->left) {
                solve(root->left);
            }
            if (root->right){
                solve(root->right);
            }
            ++odd;
        } else {
            ++odd;
            if (root->left) {
                solve(root->left);
            }
            if (root->right) {
                solve(root->right);
            }
            --odd;
        }
        --count[root->val];
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        odd = 0;
        result = 0;
        i = 0;
        solve(root);
        return result;
    }

private:
    unordered_map<int, int> count;
    int odd;
    int result;
    int i ;
};
