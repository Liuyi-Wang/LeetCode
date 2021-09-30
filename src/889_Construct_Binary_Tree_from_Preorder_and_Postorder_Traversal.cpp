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
    TreeNode* solve(const vector<int>& pre, int preb, int pree,
                    const vector<int>& post, int postb, int poste) {
        if (preb > pree) {
            return NULL;
        }
        TreeNode* root = new TreeNode(pre[preb]);
        if (preb == pree) {
            return root;
        }
        int lv = pre[preb+1], rv = post[poste-1];
        if (lv == rv) {
            TreeNode* l = solve(pre, preb+1, pree, post, postb, poste-1);
            root->left = l;
            return root;
        }
        int prer = preb+2;
        for (; prer <= pree; ++prer) {
            if (rv == pre[prer]) {
                break;
            }
        }
        int postl = poste-2;
        for (; postl >= postb; --postl) {
            if (lv == post[postl]) {
                break;
            }
        }
        TreeNode* l = solve(pre, preb+1, prer-1, post, postb, postl);
        TreeNode* r = solve(pre, prer, pree, post, postl+1, poste-1);
        root->left = l;
        root->right = r;
        return root;
    }
    
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        return solve(pre, 0, pre.size()-1, post, 0, post.size()-1);
    }
};
