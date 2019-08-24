/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class CBTInserter {
public:
    CBTInserter(TreeNode* root) {
        d_r = root;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            d_v.push_back(node);
            if (NULL != node->left) {
                q.push(node->left);
            }
            if (NULL != node->right) {
                q.push(node->right);
            }
        }
    }
    
    int insert(int v) {
        TreeNode* node = new TreeNode(v);
        d_v.push_back(node);
        int index = (d_v.size()-2)/2;
        TreeNode* p = d_v[index];
        if (index*2+1 == d_v.size()-1) {
            p->left = node;
        } else {
            p->right = node;
        }
        return p->val;
    }
    
    TreeNode* get_root() {
        return d_r;
    }
private:
    vector<TreeNode*> d_v;
    TreeNode* d_r;
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(v);
 * TreeNode* param_2 = obj->get_root();
 */
