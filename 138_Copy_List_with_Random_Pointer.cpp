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
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (NULL == head) {
            return NULL;
        }
        Node* node = head;
        while (node) {
            Node* newNode = new Node(node->val, NULL, NULL);
            d_hash[node] = newNode;
            node = node->next;
        }
        node = head;
        while (node && node->next) {
            d_hash[node]->next = d_hash[node->next];
            d_hash[node]->random = d_hash[node->random];
            node = node->next;
        }
        d_hash[node]->random = d_hash[node->random];
        return d_hash[head];
    }
    
private:
    unordered_map<Node*, Node*> d_hash;
};
