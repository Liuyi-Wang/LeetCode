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
    int minDepth(TreeNode* root) {
        if (NULL == root) {
            return 0;
        }
        d_d[root] = 1;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            root = q.front();
            q.pop();
            int d = d_d[root];
            if (NULL == root->left && NULL == root->right) {
                return d;
            }
            if (root->left) {
                d_d[root->left] = d+1;
                q.push(root->left);
            }
            if (root->right) {
                d_d[root->right] = d+1;
                q.push(root->right);
            }
        }
        return 0;
    }

private:
    unordered_map<TreeNode*, int> d_d;
};
