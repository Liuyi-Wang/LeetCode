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
    int solve(TreeNode* root) {
        if (NULL == root) {
            return 0;
        }
        int l = solve(root->left);
        int r = solve(root->right);
        ++d_hash[root->val+l+r];
        if (d_m < d_hash[root->val+l+r]) {
            d_m = d_hash[root->val+l+r];
        }
        return root->val+l+r;
    }
    
    vector<int> findFrequentTreeSum(TreeNode* root) {
        d_m = 0;
        solve(root);
        vector<int> result;
        for (unordered_map<int, int>::iterator it = d_hash.begin(); it != d_hash.end(); ++it) {
            if (d_m == it->second) {
                result.push_back(it->first);
            }
        }
        return result;
    }
    
private:
    unordered_map<int, int> d_hash;
    int d_m;
};
