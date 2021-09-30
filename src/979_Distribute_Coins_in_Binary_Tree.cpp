class Solution {
public:
    int coin(TreeNode* root) {
        if (NULL == root) {
            return 0;
        }
        int l = coin(root->left);
        int r = coin(root->right);
        d_result += abs(l)+abs(r);
        return root->val+l+r-1;
    }
    
    int distributeCoins(TreeNode* root) {
        d_result = 0;
        coin(root);
        return d_result;
    }
private:
    int d_result;
};
