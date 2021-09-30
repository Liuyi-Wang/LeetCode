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
    void solve(TreeNode* root, string s) {
        if (NULL == root->left && NULL == root->right) {
            d_result.push_back(s);
            return;
        }
        if (root->left) {
            solve(root->left, s+"->"+to_string(root->left->val));
        }
        if (root->right) {
            solve(root->right, s+"->"+to_string(root->right->val));
        }
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        if (NULL == root) {
            return d_result;
        }
        string s = to_string(root->val);
        solve(root, s);
        return d_result;
    }
    
private:
    vector<string> d_result;
};
