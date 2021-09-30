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
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* solve(TreeNode* root, const int &v, int d) {
        if (1 == d) {
            TreeNode* p = new TreeNode(v);
            p->left = root;
            return p;
        } 
        if (2 == d) {
            TreeNode* l = root->left;
            TreeNode* r = root->right;
            root->left = new TreeNode(v);
            root->right = new TreeNode(v);
            root->left->left = l;
            root->right->right = r;
            return root;
        }
        if (root->left) {
            solve(root->left, v, d-1);
        }
        if (root->right) {
            solve(root->right, v, d-1);
        }
        return root;
    }
    
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        return solve(root, v, d);
    }
};
