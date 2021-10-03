/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* node = new ListNode();
        node->next = head;
        head = node;
        int l = 0;
        node = head->next;
        while (node) {
            ++l;
            node = node->next;
        }
        ListNode* prev1 = NULL;
        ListNode* prev2 = NULL;
        node = head;
        int i = 0;
        while (node) {
            if (i == k-1) {
                prev1 = node;
            }
            if (i == l-k) {
                prev2 = node;
            }
            node = node->next;
            ++i;
        }
        ListNode *node1 = prev1->next;
        ListNode *node2 = prev2->next;
        if (node1 == node2) {
            return head->next;
        }
        if (node1->next == node2) {
            ListNode *next2 = node2->next;
            prev1->next = node2;
            node2->next = node1;
            node1->next = next2;
            return head->next;
        }
        if (node2->next == node1) {
            ListNode *next1 = node1->next;
            prev2->next = node1;
            node1->next = node2;
            node2->next = next1;
            return head->next;
        }
        ListNode *next1 = node1->next;
        ListNode *next2 = node2->next;
        prev1->next = node2;
        node2->next = next1;
        prev2->next = node1;
        node1->next = next2;
        return head->next;
    }
};
