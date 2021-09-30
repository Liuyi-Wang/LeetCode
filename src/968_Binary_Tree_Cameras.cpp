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
    void solve(TreeNode* root, int& c, int& u, int& o) {
        if (NULL == root->left && NULL == root->right) {
            o = 1;
            c = INT_MAX;
            u = 0;
            return;
        }
        int lc, lu, lo, rc, ru, ro;
        if (root->left) {
            solve(root->left, lc, lu, lo);
        }
        if (root->right) {
            solve(root->right, rc, ru, ro);
        }
        if (root->left && root->right) {
            o = 1 + min(min(lc, lu), lo) + min(min(rc, ru), ro);
            c = min(lo + min(ro, rc), ro + min(lo, lc));
            if (INT_MAX == lc || INT_MAX == rc) {
                u = INT_MAX;
            } else {
                u = lc + rc;
            }
        } else if (root->left) {
            o = 1 + min(min(lc, lu), lo);
            c = lo;
            u = lc;
        } else if (root->right) {
            o = 1 + min(min(rc, ru), ro);
            c = ro;
            u = rc;
        }
    }
    
    int minCameraCover(TreeNode* root) {
        int c, u, o;
        solve(root, c, u, o);
        return min(c, o);
    }
};
