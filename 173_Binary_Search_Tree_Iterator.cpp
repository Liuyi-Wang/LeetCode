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
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        d_it = root;
    }
    
    int next() {
        while (d_it) {
            d_s.push(d_it);
            d_it = d_it->left;
        }
        d_it = d_s.top();
        d_s.pop();
        int result = d_it->val;
        d_it = d_it->right;
        return result;
    }
    
    bool hasNext() {
        return !d_s.empty() || d_it;
    }
    
private:
    stack<TreeNode*> d_s;
    TreeNode* d_it;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
