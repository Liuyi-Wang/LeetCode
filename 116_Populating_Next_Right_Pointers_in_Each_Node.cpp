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
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
public:
    void solve(Node *root) {
        if (NULL == root || NULL == root->left) {
            return;
        }
        root->left->next = root->right;
        if (root->next) {
            root->right->next = root->next->left;
        }
        solve(root->left);
        solve(root->right);
    }
    
    Node* connect(Node* root) {
        solve(root);
        return root;
    }
};
