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
    TreeNode* solve(const vector<int> &inorder, int ib, int ie,
                    const vector<int> &postorder, int pb, int pe) {
        if (pb > pe) {
            return NULL;
        }
        TreeNode *node = new TreeNode(postorder[pe]);
        int i = ib;
        for (; i <= ie; ++i) {
            if (inorder[i] == postorder[pe]) {
                break;
            }
        }
        node->left = solve(inorder, ib, i-1, postorder, pb, pb+i-1-ib);
        node->right = solve(inorder, i+1, ie, postorder, pb+i-ib, pe-1);
        return node;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return solve(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
    }
};
