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
    void solve(TreeNode* root, int &rob, int &notRob) {
        if (NULL == root) {
            rob = 0;
            notRob = 0;
            return;
        }
        int lrob = 0, lnotRob = 0, rrob = 0, rnotRob = 0;
        solve(root->left, lrob, lnotRob);
        solve(root->right, rrob, rnotRob);
        rob = root->val+lnotRob+rnotRob;
        notRob = max(lrob, lnotRob)+max(rrob, rnotRob);
    }
    
    int rob(TreeNode* root) {
        int rob = 0;
        int notRob = 0;
        solve(root, rob, notRob);
        return max(rob, notRob);
    }
};
