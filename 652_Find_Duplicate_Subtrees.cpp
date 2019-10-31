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
    string solve(TreeNode* root) {
        if (NULL == root) {
            return "/";
        }
        string result = to_string(root->val) + " " + solve(root->left) + " " + solve(root->right);
        if (1 == d_sub[result]) {
            d_result.push_back(root);
        }
        ++d_sub[result];
        return result;
    }
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        solve(root);
        return d_result;
    }

private:
    unordered_map<string, int> d_sub;
    vector<TreeNode*> d_result;
};
