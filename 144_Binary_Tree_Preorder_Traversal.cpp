static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if (NULL == root) {
            return result;
        }
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            root = s.top();
            s.pop();
            result.push_back(root->val);
            if (root->right) {
                s.push(root->right);
            }
            if (root->left) {
                s.push(root->left);
            }
        }
        return result;
    }
};
