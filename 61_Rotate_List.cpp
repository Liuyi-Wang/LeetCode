/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (NULL == head) {
            return NULL;
        }
        ListNode* node = head;
        int len = 1;
        while (node->next) {
            ++len;
            node = node->next;
        }
        node->next = head;
        node = head;
        k %= len;
        while (k < len-1) {
            node = node->next;
            ++k;
        }
        head = node->next;
        node->next = NULL;
        return head;
    }
};
