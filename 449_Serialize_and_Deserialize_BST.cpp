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
        return de(ss);
    }
    
private:
    void se(TreeNode* root, stringstream &ss) {
        if (NULL == root) {
            ss << "/ ";
            return;
        }
        ss << root->val << " ";
        se(root->left, ss);
        se(root->right, ss);
    }
    
    TreeNode* de(stringstream &ss) {
        string s;
        ss >> s;
        if ("/" == s) {
            return NULL;
        }
        TreeNode *root = new TreeNode(atoi(s.c_str()));
        root->left = de(ss);
        root->right = de(ss);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
