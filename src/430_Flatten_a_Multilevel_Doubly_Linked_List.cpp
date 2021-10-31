/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if (!head) {
            return NULL;
        }
        stack<Node*> stk;
        Node* result = new Node();
        if (head) {
            stk.push(head);
        }
        Node* tail = result;
        while (!stk.empty()) {
            head = stk.top();
            stk.pop();
            if (head->next) {
                stk.push(head->next);
                head->next = NULL;
            }
            if (head->child) {
                stk.push(head->child);
                head->child = NULL;
            }
            tail->next = head;
            head->prev = tail;
            tail = head;
        }
        result = result->next;
        result->prev = NULL;
        return result;
    }
};
