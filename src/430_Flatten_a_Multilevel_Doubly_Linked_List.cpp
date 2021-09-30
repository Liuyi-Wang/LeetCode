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
    Node* solve(Node* head) {
        if (NULL == head) {
            return NULL;
        }
        Node* node = head;
        Node* tail = node;
        while (node) {
            if (node->child) {
                Node* c = node->child;
                Node* t = solve(c);
                node->child = NULL;
                Node* n = node->next;
                node->next = c;
                c->prev = node;
                if (n) {
                    t->next = n;
                    n->prev = t;
                }
                tail = t;
                node = n;
            } else {
                tail = node;
                node = node->next;
            }
        }
        return tail;
    }
    
    Node* flatten(Node* head) {
        solve(head);
        return head;
    }
};
