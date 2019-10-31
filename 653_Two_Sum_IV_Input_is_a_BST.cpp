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
    bool findTarget(TreeNode* root, int k) {
        if (NULL == root) {
            return false;
        }
        if (d_n.find(k-root->val) != d_n.end()) {
            d_n.insert(root->val);
            return true;
        }
        d_n.insert(root->val);
        if (findTarget(root->left, k)) {
            return true;
        }
        if (findTarget(root->right, k)) {
            return true;
        }
        return false;
    }
    
private:
    unordered_set<int> d_n;
};
