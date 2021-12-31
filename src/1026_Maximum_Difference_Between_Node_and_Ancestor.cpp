/**
 *  Time:
 *  O(n)
 *  Space:
 *  O(n)
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
    int maxAncestorDiff(TreeNode* root) {
        result = 0;
        int maxv, minv;
        dfs(root, maxv, minv);
        return result;
    }
    
    void dfs(TreeNode* root, int& maxv, int& minv) {
        if (root->left && root->right) {
            int lmax, lmin, rmax, rmin;
            dfs(root->left, lmax, lmin);
            dfs(root->right, rmax, rmin);
            maxv = max(lmax, rmax);
            maxv = max(maxv, root->val);
            minv = min(lmin, rmin);
            minv = min(minv, root->val);
            result = max(result, abs(root->val-lmax));
            result = max(result, abs(root->val-rmax));
            result = max(result, abs(root->val-lmin));
            result = max(result, abs(root->val-rmin));
            return;
        } else if (root->left) {
            int lmax, lmin;
            dfs(root->left, lmax, lmin);
            maxv = max(lmax, root->val);
            minv = min(lmin, root->val);
            result = max(result, abs(root->val-lmax));
            result = max(result, abs(root->val-lmin));
            return;
        } else if (root->right) {
            int rmax, rmin;
            dfs(root->right, rmax, rmin);
            maxv = max(rmax, root->val);
            minv = min(rmin, root->val);
            result = max(result, abs(root->val-rmax));
            result = max(result, abs(root->val-rmin));
            return;
        }
        maxv = root->val;
        minv = root->val;
    }
};
