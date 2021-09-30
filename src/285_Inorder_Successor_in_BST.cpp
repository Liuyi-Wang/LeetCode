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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        stack<TreeNode*> s;
        s.push(root);
        bool find = false;
        while (!s.empty()) {
            root = s.top();
            s.pop();
            if (NULL == root->left && NULL == root->right) {
                if (find) {
                    return root;
                }
                if (root->val == p->val) {
                    find = true;
                }
                continue;
            }
            TreeNode *l = root->left;
            TreeNode *r = root->right;
            root->left = NULL;
            root->right = NULL;
            if (r) {
                s.push(r);
            }
            s.push(root);
            if (l) {
                s.push(l);
            }
        }
        return NULL;
    }
};
