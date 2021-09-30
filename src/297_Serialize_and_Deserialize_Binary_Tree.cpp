/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        stringstream ss;
        se(root, ss);
        return ss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        TreeNode* root;
        de(root, ss);
        return root;
    }
    
private:
    void se(TreeNode* root, stringstream& ss) {
        if (NULL == root) {
            ss << "/ ";
            return;
        }
        ss << root->val << " ";
        se(root->left, ss);
        se(root->right, ss);
    }
    
    void de(TreeNode* &root, stringstream& ss) {
        string s;
        ss >> s;
        if ("/" == s) {
            root = NULL;
            return;
        }
        root = new TreeNode(atoi(s.c_str()));
        de(root->left, ss);
        de(root->right, ss);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
