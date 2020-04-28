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
    void solve(TreeNode* root, int level) {
        if (NULL == root) {
            return;
        }
        if (level >= d_l.size()) {
            d_l.push_back(root->val);
        }
        solve(root->left, level+1);
        solve(root->right, level+1);
    }
    
    int findBottomLeftValue(TreeNode* root) {
        solve(root, 0);
        return d_l.back();
    }
    
private:
    vector<int> d_l;
};
