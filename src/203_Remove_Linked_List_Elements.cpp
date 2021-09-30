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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* result = new ListNode(0);
        ListNode* tail = result;
        while (head) {
            if (val != head->val) {
                tail->next = head;
                tail = head;
            }
            head = head->next;
        }
        tail->next = NULL;
        return result->next;
    }
};
