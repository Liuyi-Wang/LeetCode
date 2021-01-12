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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> imap;
        for (int i = 0; i < inorder.size(); ++i) {
            imap[inorder[i]] = i;
        }
        return recursion(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1, imap);
    }
    
    TreeNode* recursion(const vector<int>& iorder, int ib, int ie,
                        const vector<int>& porder, int pb, int pe,
                        const unordered_map<int, int>& imap) {
        if (ib > ie) {
            return NULL;
        }
        int index = imap.find(porder[pe])->second;
        TreeNode* l = recursion(iorder, ib, index-1, porder, pb, pb+index-1-ib, imap);
        TreeNode* r = recursion(iorder, index+1, ie, porder, pb+index-ib, pe-1, imap);
        return new TreeNode(porder[pe], l, r);
    }
};
