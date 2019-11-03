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
    int closestValue(TreeNode* root, double target) {
        if (NULL == root->left && NULL == root->right) {
            return root->val;
        }
        if (NULL == root->left) {
            int r = closestValue(root->right, target);
            if (abs(target-root->val) < abs(target-r)) {
                return root->val;
            } else {
                return r;
            }
        }
        if (NULL == root->right) {
            int l = closestValue(root->left, target);
            if (abs(target-root->val) < abs(target-l)) {
                return root->val;
            } else {
                return l;
            }
        }
        int r = closestValue(root->right, target);
        int l = closestValue(root->left, target);
        double dr = abs(target-r);
        double dl = abs(target-l);
        double d = abs(target-root->val);
        if (dr < dl && dr < d) {
            return r;
        }
        if (dl < dr && dl < d) {
            return l;
        }
        return root->val;
    }
};
