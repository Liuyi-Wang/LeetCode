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
    unordered_map<int, int> imap;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); ++i) {
            imap[inorder[i]] = i;
        }
        return recursion(preorder, 0, preorder.size()-1,
                         inorder, 0, inorder.size()-1);
    }
    
    TreeNode* recursion(const vector<int>& porder, int pb, int pe,
                        const vector<int>& iorder, int ib, int ie) {
        if (pb > pe) {
            return NULL;
        }
        int index = imap.find(porder[pb])->second;
        TreeNode* l = recursion(porder, pb+1, pb+index-ib, iorder, ib, index-1);
        TreeNode* r = recursion(porder, pb+index-ib+1, pe, iorder, index+1, ie);
        return new TreeNode(porder[pb], l, r);
    }
};
