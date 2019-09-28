static const int __ = []() {
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
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        d_find = false;
        if (NULL != root) {
            d_nodes.push(root);
        }
    }
    
    /** @return the next smallest number */
    int next() {
        hasNext();
        d_find = false;
        return d_next->val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        if (d_find) {
            return true;
        }
        while (!d_nodes.empty()) {
            TreeNode* node = d_nodes.top();
            d_nodes.pop();
            if (NULL == node->left && NULL == node->right) {
                d_next = node;
                d_find = true;
                return true;
            }
            if (NULL != node->right) {
                d_nodes.push(node->right);
                node->right = NULL;
            }
            TreeNode* left = node->left;
            node->left = NULL;
            d_nodes.push(node);
            if (NULL != left) {
                d_nodes.push(left);
            }
        }
        return false;
    }
private:
    stack<TreeNode*> d_nodes;
    bool d_find;
    TreeNode* d_next;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
