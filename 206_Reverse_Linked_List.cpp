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
    ListNode* reverseList(ListNode* head) {
        if (NULL == head) {
            return NULL;
        }
        ListNode* next = head->next;
        head->next = NULL;
        while (NULL != next) {
            ListNode* node = next->next;
            next->next = head;
            head = next;
            next = node;
        }
        return head;
    }
};
