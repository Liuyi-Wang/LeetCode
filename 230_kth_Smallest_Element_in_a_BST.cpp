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
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        bool find = false;
        return recursion(root, k, count, find);
    }
    
    int recursion(TreeNode* root, const int k, int& count, bool& find) {
        if (NULL == root) {
            count = 0;
            return 0;
        }
        int lc = 0;
        bool lf = false;
        int l = recursion(root->left, k, lc, lf);
        if (lf) {
            find = true;
            return l;
        }
        if (lc+1 == k) {
            find = true;
            return root->val;
        }
        int rc = 0;
        bool rf = false;
        int r = recursion(root->right, k-1-lc, rc, rf);
        if (rf) {
            find = true;
            return r;
        }
        count = lc + 1 + rc;
        return 0;
    }
};
