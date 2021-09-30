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
    /*
    bool hasPathSum(TreeNode* root, int sum) {
        if (NULL == root) {
            return false;
        }
        return recursion(root, sum, 0);
    }
    
    bool recursion(TreeNode* root, const int& target, const int& sum) {
        if (NULL == root->left && NULL == root->right) {
            if (target == sum+root->val) {
                return true;
            }
            return false;
        }
        if (root->left && recursion(root->left, target, sum+root->val)) {
            return true;
        }
        if (root->right && recursion(root->right, target, sum+root->val)) {
            return true;
        }
        return false;
    }
    */
    bool hasPathSum(TreeNode* root, int sum) {
        if (NULL == root) {
            return false;
        }
        sum -= root->val;
        if (NULL == root->left && NULL == root->right) {
            return 0 == sum;
        }
        return hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
    }
};
