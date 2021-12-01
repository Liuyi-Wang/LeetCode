/**
 *  Time:
 *  O(n)
 *  Space:
 *  O(1)
 */
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        if (head == NULL) {
            head = new Node(insertVal);
            head->next = head;
            return head;
        }
        if (head->next == head) {
            head->next = new Node(insertVal, head);
            return head;
        }
        Node* n1 = head;
        Node* n2 = head->next;
        while (n2 != head) {
            if (n1->val <= n2->val && n1->val <= insertVal && insertVal <= n2->val) {
                Node* node = new Node(insertVal, n2);
                n1->next = node;
                return head;
            } else if (n1->val > n2->val && (insertVal <= n2->val || n1->val <= insertVal))  {
                Node* node = new Node(insertVal, n2);
                n1->next = node;
                return head;
            }
            n2 = n2->next;
            n1 = n1->next;
        }
        Node* node = new Node(insertVal, n2);
        n1->next = node;
        return head;
    }
};
