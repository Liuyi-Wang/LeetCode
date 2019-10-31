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
    string tree2str(TreeNode* t) {
        if (NULL == t) {
            return "";
        }
        string s = to_string(t->val);
        if (NULL == t->left && NULL == t->right) {
            return s;
        }
        if (t->left && t->right) {
            s += "(";
            s += tree2str(t->left);
            s += ")";
            s += "(";
            s += tree2str(t->right);
            s += ")";
            return s;
        }
        if (t->left) {
            s += "(";
            s += tree2str(t->left);
            s += ")";
            return s;
        }
        if (t->right) {
            s += "()";
            s += "(";
            s += tree2str(t->right);
            s += ")";
            return s;
        }
        return s;
    }
};
