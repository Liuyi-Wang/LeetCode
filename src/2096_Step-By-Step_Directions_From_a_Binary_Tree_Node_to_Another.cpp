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
    string result;
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        vector<int> n1, n2;
        vector<char> d1, d2;
        dfs(root, startValue, n1, d1);
        dfs(root, destValue, n2, d2);
        int i = 0;
        while (i < n1.size() && i < n2.size() && n1[i] == n2[i]) {
            ++i;
        }
        --i;
        string result((int)d1.size()-1-i+1, 'U');
        for (; i < d2.size(); ++i) {
            result += d2[i];
        }
        return result;
    }
    
    bool dfs(TreeNode* root, int target, vector<int>& n, vector<char>& d) {
        if (root == NULL) {
            return false;
        }
        if (root->val == target) {
            n.push_back(root->val);
            return true;
        }
        n.push_back(root->val);
        d.push_back('L');
        if (dfs(root->left, target, n, d)) {
            return true;
        }
        d.back() = 'R';
        if (dfs(root->right, target, n, d)) {
            return true;
        }
        n.pop_back();
        d.pop_back();
        return false;
    }   
};
