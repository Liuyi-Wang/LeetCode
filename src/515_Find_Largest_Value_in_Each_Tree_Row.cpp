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
    void solve(TreeNode *root, int level) {
        if (NULL == root) {
            return;
        }
        if (level < d_result.size()) {
            d_result[level] = max(d_result[level], root->val);
        } else {
            d_result.push_back(root->val);
        }
        solve(root->left, level+1);
        solve(root->right, level+1);
    }
    
    vector<int> largestValues(TreeNode* root) {
        solve(root, 0);
        return d_result;
    }
    
private:
    vector<int> d_result;
};
