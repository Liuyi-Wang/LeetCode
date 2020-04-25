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
    TreeNode* solve(const string &s, int l, int r) {
        if (l > r) {
            return NULL;
        }
        int i = l;
        if ('-' == s[i]) {
            ++i;
        }
        while (i <= r && isdigit(s[i])) {
            ++i;
        }
        int val = atoi(s.substr(l, i-l).c_str());
        TreeNode *root = new TreeNode(val);
        if (i > r) {
            return root;
        }
        int begin = i;
        int count = 1;
        ++i;
        while (i <= r && 0 != count) {
            if ('(' == s[i]) {
                ++count;
            } else if (')' == s[i]) {
                --count;
            }
            ++i;
        }
        //cout << "count=" << count << endl;
        //cout << i << endl;
        TreeNode *left = solve(s, begin+1, i-2);
        TreeNode *right = solve(s, i+1, r-1);
        root->left = left;
        root->right = right;
        return root;
    }
    
    TreeNode* str2tree(string s) {
        return solve(s, 0, s.size()-1);
    }
};
