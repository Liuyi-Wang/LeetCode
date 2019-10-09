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
    void solve(TreeNode* root, const vector<int>& voyage, int begin, int end) {
        if (NULL == root) {
            return;
        }
        if (begin > end || root->val != voyage[begin]) {
            d_result = vector<int>(1, -1);
            return;
        }
        if (NULL == root->left) {
            solve(root->right, voyage, begin+1, end);
        } else if (NULL == root->right) {
            solve(root->left, voyage, begin+1, end);
        } else {
            if (root->left->val == voyage[begin+1]) {
                int i = begin+2;
                bool find = false;
                for (; i <= end; ++i) {
                    if (voyage[i] == root->right->val) {
                        find = true;
                        break;
                    }
                }
                if (!find) {
                    d_result = vector<int>(1, -1);
                    return;
                }
                solve(root->left, voyage, begin+1, i-1);
                if (!d_result.empty() && d_result[0] == -1) {
                    return;
                }
                solve(root->right, voyage, i, end);
            } else {
                d_result.push_back(root->val);
                int i = begin+2;
                bool find = false;
                for (; i <= end; ++i) {
                    if (voyage[i] == root->left->val) {
                        find = true;
                        break;
                    }
                }
                if (!find) {
                    d_result = vector<int>(1, -1);
                    return;
                }
                solve(root->right, voyage, begin+1, i-1);
                if (!d_result.empty() && d_result[0] == -1) {
                    return;
                }
                solve(root->left, voyage, i, end);
            }
        }
    }
    
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        solve(root, voyage, 0, voyage.size()-1);
        return d_result;
    }
    
private:
    vector<int> d_result;
};
