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
    Node* parent;
};
*/

class Solution {
public:
    Node* inorderSuccessor(Node* node) {
        if (node->right) {
            Node* l = node->right;
            while (l->left) {
                l = l->left;
            }
            if (l) {
                return l;
            }
            Node* r = inorderSuccessor(l);
            if (r) {
                return r;
            }
            return l;
        }
        Node* p = node->parent;
        while (p && p->right == node) {
            node = p;
            p = p->parent;
        }
        return p;
    }
};
