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
    TreeNode* solve(const vector<int>& preorder, int begin, int end) {
        if (begin > end) {
            return NULL;
        }
        TreeNode* node = new TreeNode(preorder[begin]);
        if (begin == end) {
            return node;
        }
        int l = begin+1, r = end;
        while (l < r-1) {
            int mid = (l+r)/2;
            if (preorder[mid] > preorder[begin]) {
                r = mid-1;
            } else {
                l = mid;
            }
        }
        int leftEnd = 0;
        if (l == r) {
            if (preorder[l] < preorder[begin]) {
                leftEnd = l;
            } else {
                node->right = solve(preorder, begin+1, end);
                return node;
            }
        } else {
            if (preorder[r] < preorder[begin]) {
                leftEnd = r;
            } else if (preorder[l] < preorder[begin]) {
                leftEnd = l;
            } else {
                node->right = solve(preorder, begin+1, end);
                return node;
            }
        }
        node->left = solve(preorder, begin+1, leftEnd);
        node->right = solve(preorder, leftEnd+1, end);
        return node;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return solve(preorder, 0, preorder.size()-1);
    }
};
