static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

/*
// Definition for a Node.
class Node {
public:
    int val = NULL;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
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

    // Encodes an n-ary tree to a binary tree.
    TreeNode* encode(Node* root) {
        if (NULL == root) {
            return NULL;
        }
        if (0 == root->children.size()) {
            return new TreeNode(root->val);
        } else {
            TreeNode* treeNode = new TreeNode(root->val);
            treeNode->left = encode(root->children[0]);
            TreeNode* r = treeNode->left;
            for (int i = 1; i < root->children.size(); ++i) {
                r->right = encode(root->children[i]);
                r = r->right;
            }
            return treeNode;
        }
    } 

    // Decodes your binary tree to an n-ary tree.
    Node* decode(TreeNode* root) {
        if (NULL == root) {
            return NULL;
        }
        Node* node = new Node(root->val);
        TreeNode* r = root->left;
        while (r) {
            node->children.push_back(decode(r));
            r = r->right;
        }
        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(root));
