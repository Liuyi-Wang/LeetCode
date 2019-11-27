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
    void solve(int begin, int end) {
        if (d_generated.find({begin, end}) != d_generated.end()) {
            return;
        }
        if (begin == end) {
            TreeNode *node = new TreeNode(begin);
            vector<TreeNode*> v = {node};
            d_generated[{begin, end}] = v;
            return;
        }
        solve(begin+1 , end);
        for (int i = 0; i < d_generated[{begin+1, end}].size(); ++i) {
            TreeNode *b = new TreeNode(begin);
            b->right = d_generated[{begin+1, end}][i];
            d_generated[{begin, end}].push_back(b);
        }
        solve(begin, end-1);
        for (int i = 0; i < d_generated[{begin, end-1}].size(); ++i) {
            TreeNode *e = new TreeNode(end);
            e->left = d_generated[{begin, end-1}][i];
            d_generated[{begin, end}].push_back(e);
        }
        for (int i = begin+1; i <= end-1; ++i) {
            solve(begin, i-1);
            solve(i+1, end);
            for (int j = 0; j < d_generated[{begin, i-1}].size(); ++j) {
                for (int k = 0; k < d_generated[{i+1, end}].size(); ++k) {
                    TreeNode *n = new TreeNode(i);
                    n->left = d_generated[{begin, i-1}][j];
                    n->right = d_generated[{i+1, end}][k];
                    d_generated[{begin, end}].push_back(n);
                }
            }
        }
    }
    
    vector<TreeNode*> generateTrees(int n) {
        if (n < 1) {
            return vector<TreeNode*>();
        }
        solve(1, n);
        return d_generated[{1, n}];
    }
    
private:
    map<pair<int, int>, vector<TreeNode*>> d_generated;
};
