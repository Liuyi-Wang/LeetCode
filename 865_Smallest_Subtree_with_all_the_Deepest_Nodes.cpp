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
    void solve(TreeNode* root, int d) {
        if (NULL == root) {
            return;
        }
        d_depth[root->val] = d;
        d_nodes[root->val] = root;
        d_parents.insert(root->val);
        if (NULL == root->left && NULL == root->right) {
            if (d > d_depth[d_deepest]) {
                d_deepest = root->val;
                d_commons = d_parents;
            } else if (d == d_depth[d_deepest]) {
                set<int> intersect;
                set_intersection(d_commons.begin(), d_commons.end(), d_parents.begin(), d_parents.end(),
                                 std::inserter(intersect,intersect.begin()));
                d_commons = intersect;
            }
            d_parents.erase(d_parents.find(root->val));   
            return;
        }
        solve(root->left, d+1);
        solve(root->right, d+1);
        d_parents.erase(d_parents.find(root->val));   
    }
    
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        d_depth = vector<int>(500, 0);
        d_nodes = vector<TreeNode*>(500, NULL);
        d_deepest = root->val;
        d_depth[root->val] = 0;
        d_nodes[root->val] = root;
        solve(root, 0);
        int result = root->val;
        for (set<int>::iterator it = d_commons.begin(); it != d_commons.end(); ++it) {
            if (d_depth[*it] > d_depth[result]) {
                result = *it;
            }
        }
        return d_nodes[result];
    }

private:
    vector<int> d_depth;
    vector<TreeNode*> d_nodes;
    set<int> d_parents;
    set<int> d_commons;
    int d_deepest;
};
