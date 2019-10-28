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
    void solveTarget(TreeNode* root, int d, const int &K) {
        if (NULL == root) {
            return;
        }
        if (d == K) {
            d_result.push_back(root->val);
            return;
        }
        solveTarget(root->left, d+1, K);
        solveTarget(root->right, d+1, K);
    }
    
    void solve(TreeNode* root, int d, const int &K) {
        if (NULL == root) {
            return;
        }
        if (d == K) {
            d_result.push_back(root->val);
            return;
        }
        if (d_left.find(root->val) == d_left.end()) {
            solve(root->right, d+1, K);
            solve(root->left, d+1, K);
            return;
        }
        if (d_left[root->val]) {
            solve(root->right, d+1, K);
            return;
        }
        if (!d_left[root->val]) {
            solve(root->left, d+1, K);
            return;
        }
    }
    
    void find(TreeNode* root, int &d, const int &K) {
        if (NULL == root) {
            return;
        }    
        if (root->val == d_target) {
            d_find = true;
            d = 0;
            return;
        }
        int ld = 0;
        find(root->left, ld, K);
        if (d_find) {
            d = ld+1;
            d_parents.push_back(root);
            d_left[root->val] = true;
            d_d[root->val] = d;
            return;
        }
        int rd = 0;
        find(root->right, rd, K);
        if (d_find) {
            d = rd+1;
            d_parents.push_back(root);
            d_left[root->val] = false;
            d_d[root->val] = d;
            return;
        }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        d_find = false;
        d_target = target->val;
        int d = 0;
        find(root, d, K);
        for (auto p:d_parents) {
            solve(p, d_d[p->val], K);
        }
        solveTarget(target, 0, K);
        return d_result;
    }

private:
    bool d_find;
    vector<int> d_result;
    int d_target;
    vector<TreeNode*> d_parents;
    unordered_map<int, bool> d_left;
    unordered_map<int, int> d_d;
};
