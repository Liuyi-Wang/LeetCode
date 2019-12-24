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
    vector<int> findMode(TreeNode* root) {
        vector<int> result;
        if (NULL == root) {
            return result;
        }
        stack<TreeNode*> s;
        s.push(root);
        TreeNode *prev = NULL;
        int mode = 0;
        int count = 0;
        while (!s.empty()) {
            root = s.top();
            s.pop();
            if (NULL == root->left && NULL == root->right) {
                if (prev && prev->val == root->val) {
                    ++count;
                } else if (NULL == prev) {
                    prev = root;
                    count = 1;
                } else {
                    if (count > mode) {
                        result.clear();
                        result.push_back(prev->val);
                        mode = count;
                    } else if (count == mode) {
                        result.push_back(prev->val);
                    }
                    prev = root;
                    count = 1;
                }
            } else {
                if (root->right) {
                    s.push(root->right);
                    root->right = NULL;
                }
                s.push(root);
                if (root->left) {
                    s.push(root->left);
                    root->left = NULL;
                }
            }
        }
        if (count > mode) {
            result.clear();
            result.push_back(prev->val);
        } else if (count == mode) {
            result.push_back(prev->val);
        }
        return result;
    }
};
