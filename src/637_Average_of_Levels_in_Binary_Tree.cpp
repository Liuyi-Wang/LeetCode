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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> result;
        vector<vector<TreeNode*>> levels(2, vector<TreeNode*>());
        int level = 0;
        levels[level%2].push_back(root);
        result.push_back(root->val);
        ++level;
        while (true) {
            levels[level%2].clear();
            double sum = 0;
            for (auto root:levels[(level-1)%2]) {
                if (root->left) {
                    sum += root->left->val;
                    levels[level%2].push_back(root->left);
                }
                if (root->right) {
                    sum += root->right->val;
                    levels[level%2].push_back(root->right);
                }
            }
            if (0 == levels[level%2].size()) {
                break;
            }
            result.push_back(sum/levels[level%2].size());
            ++level;
        }
        return result;
    }
};
