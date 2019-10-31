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
    void hash(TreeNode* root) {
        if (NULL == root) {
            return;
        }
        d_n.insert(root->val);
        hash(root->left);
        hash(root->right);
    }
    
    bool solve(TreeNode* root, const int &t) {
        if (NULL == root) {
            return false;
        }
        if (d_n.find(t-root->val) != d_n.end()) {
            return true;
        }
        if (solve(root->left, t)) {
            return true;
        }
        if (solve(root->right, t)) {
            return true;
        }
        return false;
    }
    
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        hash(root1);
        return solve(root2, target);
    }
    
private:
    unordered_set<int> d_n;
};
