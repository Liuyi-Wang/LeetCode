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
    int downPath(TreeNode* &root, const int& limit,
                 TreeNode* parent, int upPath, bool left) {
        int down = root->val;
        if (root->left && root->right) {
            int ld = downPath(root->left, limit, root, upPath + root->val, true);
            int rd = downPath(root->right, limit, root, upPath + root->val, false);
            down += max(ld, rd);
        } else if (root->left) {
            int ld = downPath(root->left, limit, root, upPath + root->val, true);
            down += ld;
        } else if (root->right){
            int rd = downPath(root->right, limit, root, upPath + root->val, false);
            down += rd;
        }
        if (upPath + down < limit) {
            ///delete root;
            root = NULL;
            if (parent == NULL) {
                return 0;
            } 
            if (left) {
                parent->left = NULL;
            } else {
                parent->right = NULL;
            }
        }
        return down;
    }
    
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        if (root == NULL) {
            return root;
        }
        downPath(root, limit, NULL, 0, true);
        return root;
    }
};
