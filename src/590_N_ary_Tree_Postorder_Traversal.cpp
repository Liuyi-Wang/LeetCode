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
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> result;
        if (NULL == root) {
            return result;
        }
        stack<Node*> s;
        s.push(root);
        while (!s.empty()) {
            root = s.top();
            s.pop();
            result.push_back(root->val);
            for (auto c:root->children) {
                s.push(c);
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
