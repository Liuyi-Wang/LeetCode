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
    int largestBSTSubtree(TreeNode* root) {
        result = 0;
        int mx = INT_MIN, mn = INT_MAX;
        count(root, mx, mn);
        return result;
    }
    
    int count(TreeNode* root, int& mx, int& mn) {
        if (root == NULL) {
            return 0;
        }
        int lmx = INT_MIN, lmn = INT_MAX, rmx = INT_MIN, rmn = INT_MAX;
        int l = count(root->left, lmx, lmn);
        int r = count(root->right, rmx, rmn);
        if (root->left && root->right) {
            if ((lmx < root->val && l != -1) && (root->val < rmn && r != -1)) {
                result = max(result, 1+l+r);
                mx = rmx;
                mn = lmn;
                return 1+l+r;
            } else {
                return -1;
            }
        } else if (root->left) {
            if (lmx < root->val && l != -1) {
                result = max(result, 1+l);
                mx = root->val;
                mn = lmn;
                return 1+l;
            } else {
                return -1;
            }
        } else if (root->right) {
            if (rmn > root->val && r != -1) {
                result = max(result, 1+r);
                mx = rmx;
                mn = root->val;
                return 1+r;
            } else {
                return -1;
            }
        } else {
            result = max(result, 1);
            mx = root->val;
            mn = root->val;
            return 1;
        }
    }
};
