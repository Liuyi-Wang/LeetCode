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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return sol(preorder, 0, preorder.size()-1);
    }
    
    TreeNode* sol(const vector<int>& preorder, int begin, int end) {
        if (begin > end) {
            return NULL;
        }
        if (begin == end) {
            return new TreeNode(preorder[begin]);
        }
        TreeNode* node = new TreeNode(preorder[begin]);
        int i = begin+1;
        for (; i <= end; ++i) {
            if (preorder[i] > preorder[begin]) {
                break;
            }
        }
        node->left = sol(preorder, begin+1, i-1);
        node->right = sol(preorder, i, end);
        return node;
    }
};
