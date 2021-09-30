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
    Node* connect(Node* root) {
        if (NULL == root) {
            return NULL;
        }
        vector<Node*> level;
        level.push_back(root);
        while (level.size() > 0) {
            vector<Node*> v;
            for (int i = 0; i < level.size()-1; ++i) {
                level[i]->next = level[i+1];
                if (level[i]->left) {
                    v.push_back(level[i]->left);
                }
                if (level[i]->right) {
                    v.push_back(level[i]->right);
                }
            }
            if (level.back()->left) {
                v.push_back(level.back()->left);
            }
            if (level.back()->right) {
                v.push_back(level.back()->right);
            }
            level = v;
        }
        return root;
    }
};
