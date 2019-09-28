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
    bool isValid(TreeNode* root, long long& maxV, long long& minV) {
        if (NULL == root) {
            return true;
        }
        long long lMax = LLONG_MIN, lMin = LLONG_MAX;
        if (!isValid(root->left, lMax, lMin)) {
            return false;
        } 
        long long rMax = LLONG_MIN, rMin = LLONG_MAX;
        if (!isValid(root->right, rMax, rMin)) {
            return false;
        } 
        if (lMax >= root->val) {
            return false;
        }
        if (rMin <= root->val) {
            return false;
        }
        maxV = max(static_cast<long long>(root->val), rMax);
        minV = min(static_cast<long long>(root->val), lMin);
        return true;
    }
    
    bool isValidBST(TreeNode* root) {
        long long max = LLONG_MIN, min = LLONG_MAX;
        return isValid(root, max, min);
    }
};
