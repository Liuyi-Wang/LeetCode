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
    struct less_than {
        inline bool operator() (const pair<double, int> &p1,
                                const pair<double, int> &p2) {
            return p1.first < p2.first;
        }    
    };
    
    void solve(TreeNode* root, const double &target, const int &k) {
        if (NULL == root) {
            return;
        }
        if (d_s.size() < k) {
            d_s.push(pair<double, int>(abs(target-root->val), root->val));
        } else if (d_s.top().first > abs(target-root->val)) {
            d_s.pop();
            d_s.push(pair<double, int>(abs(target-root->val), root->val));
        }
        solve(root->left, target, k);
        solve(root->right, target, k);
    }
    
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        solve(root, target, k);
        vector<int> result(k, 0);
        for (int i = 0; i < k; ++i) {
            result[i] = d_s.top().second;
            d_s.pop();
        }
        return result;
    }
    
private:
    priority_queue<pair<double, int>, vector<pair<double, int>>, less_than> d_s;
};
