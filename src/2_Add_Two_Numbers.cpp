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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* head = new ListNode(0);
        ListNode* tail = head;
        while (NULL != l1 && NULL != l2) {
            int sum = l1->val+l2->val+carry;
            carry = sum/10;
            tail->next = new ListNode(sum%10);
            tail = tail->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while (NULL != l1) {
            int sum = l1->val+carry;
            carry = sum/10;
            tail->next = new ListNode(sum%10);
            tail = tail->next;
            l1 = l1->next;
        }
        while (NULL != l2) {
            int sum = l2->val+carry;
            carry = sum/10;
            tail->next = new ListNode(sum%10);
            tail = tail->next;
            l2 = l2->next;
        }
        if (carry) {
            tail->next = new ListNode(carry);
        }
        tail = head->next;
        delete head;
        return tail;
    }
};
