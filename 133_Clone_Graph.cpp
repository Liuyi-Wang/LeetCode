/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (NULL == node) {
            return NULL;
        }
        Node *newNode = NULL;
        if (d_hash.find(node) == d_hash.end()) {
            newNode = new Node(node->val);
            d_hash[node] = newNode;
            for (int i = 0; i < node->neighbors.size(); ++i) {
                newNode->neighbors.push_back(cloneGraph(node->neighbors[i]));
            }
        } else {
            newNode = d_hash[node];
        }
        return newNode;
    }

private:
    unordered_map<Node*, Node*> d_hash;
};
