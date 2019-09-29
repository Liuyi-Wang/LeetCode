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
    TreeNode* build(const vector<int>& preorder, int pb, int pe,
                    const vector<int>& inorder, int ib, int ie) {
        if (pb > pe) {
            return NULL;
        }
        TreeNode* node = new TreeNode(preorder[pb]);
        int index = ib;
        for (; index <= ie; ++index) {
            if (preorder[pb] == inorder[index]) {
                break;
            }
        }
        node->left = build(preorder, pb+1, pb+index-ib, inorder, ib, index-1);
        node->right = build(preorder, pb+index-ib+1, pe, inorder, index+1, ie);
        return node;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);    
    }
};
