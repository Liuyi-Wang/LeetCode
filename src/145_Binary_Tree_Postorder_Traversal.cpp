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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if (NULL == root) {
            return result;
        }
        stack<TreeNode*> s;
        s.push(root);
        TreeNode* last = root;
        while (!s.empty()) {
            root = s.top();
            s.pop();
            if (NULL == root->left && NULL == root->right) {
                result.push_back(root->val);
                last = root;
                continue;
            }
            if (root->right == last || root->left == last) {
                result.push_back(root->val);
                last = root;
                continue;
            }
            s.push(root);
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
