/**
 *  Time:
 *  O(n)
 *  Space:
 *  O(1)
 */
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
        for (int i = 0; i < inorder.size(); ++i) {
            d_hash[inorder[i]] = i;
        }
        return build(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
    }
    
    TreeNode* build(const vector<int>& inorder, int inBegin, int inEnd,
                    const vector<int>& postorder, int postBegin, int postEnd) {
        if (inBegin > inEnd) {
            return NULL;
        }
        if (inBegin == inEnd) {
            return new TreeNode(inorder[inBegin]);
        }
        TreeNode* node = new TreeNode(postorder[postEnd]);
        int i = d_hash[postorder[postEnd]];
        node->left = build(inorder, inBegin, i-1, postorder, postBegin, postBegin-1+i-1-inBegin+1);
        node->right = build(inorder, i+1, inEnd, postorder, postBegin-1+i-1-inBegin+1+1, postEnd-1);
        return node;
    }
    
private:
    unordered_map<int, int> d_hash;
};
