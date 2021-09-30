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
    void solve(TreeNode* root) {
        if (NULL == root) {
            return;
        }
        if (NULL == root->left && NULL == root->right) {
            d_l.push_back(root->val);
            return;
        }
        solve(root->left);
        solve(root->right);
    }
    
    bool compare(TreeNode* root) {
        if (NULL == root) {
            return true;
        }
        if (NULL == root->left && NULL == root->right) {
            if (d_i >= d_l.size()) {
                return false;
            }
            if (d_l[d_i] == root->val) {
                ++d_i;
                return true;
            }
            return false;
        }
        if (!compare(root->left)) {
            return false;
        }
        return compare(root->right);
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        solve(root1);
        d_i = 0;
        return compare(root2);
    }

private:
    vector<int> d_l;
    int d_i;
};
