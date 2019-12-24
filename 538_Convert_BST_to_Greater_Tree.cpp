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
    TreeNode* convertBST(TreeNode* root) {
        if (NULL == root) {
            return root;
        }
        TreeNode *node = root;
        stack<TreeNode*> s;
        s.push(node);
        int sum = 0;
        unordered_set<TreeNode*> v;
        while (!s.empty()) {
            node = s.top();
            s.pop();
            if (NULL == node->left && NULL == node->right) {
                int t = node->val;
                node->val += sum;
                sum += t;
            } else if (v.find(node) != v.end()) {
                int t = node->val;
                node->val += sum;
                sum += t;
            } else {
                v.insert(node);
                if (node->left) {
                    s.push(node->left);
                }
                s.push(node);
                if (node->right) {
                    s.push(node->right);
                }
            }
        }
        return root;
    }
};
