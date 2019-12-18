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

    Node() {}

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/
class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        if (NULL == head) {
            head = new Node(insertVal, NULL);
            head->next = head;
            return head;
        }
        Node *result = head;
        if (head->val == insertVal) {
            Node *next = head->next;
            Node *node = new Node(insertVal, NULL);
            head->next = node;
            node->next = next;
            return result;
        }
        Node *t = head->next;
        Node *p = head;
        while (t != head && t->val == head->val) {
            t = t->next;
            p = p->next;
        }
        if (t == head) {
            Node *next = head->next;
            Node *node = new Node(insertVal, NULL);
            head->next = node;
            node->next = next;
            return result;
        }
        head = p;
        if (head->val > insertVal) {
            while (head->next->val >= head->val) {
                head = head->next;
            }
            t = head->next;
            if (insertVal <= t->val) {
                Node *node = new Node(insertVal, NULL);
                node->next = t;
                head->next = node;
                return result;
            }
            head = t;
            while (head->next->val < insertVal) {
                head = head->next;
            }
            Node *node = new Node(insertVal, NULL);
            node->next = head->next;
            head->next = node;
            return result;
        }
        while (head->next->val < insertVal && head->next->val >= head->val) {
            head = head->next;
        }
        Node *node = new Node(insertVal, NULL);
        node->next = head->next;
        head->next = node;
        return result;
    }
};
