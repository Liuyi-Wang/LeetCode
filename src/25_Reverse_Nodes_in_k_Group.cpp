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
    ListNode* reverse(ListNode* prev, int k) {
        ListNode* head = prev->next;
        ListNode* tail = prev->next;
        ListNode* next = head->next;
        --k;
        while (k > 0) {
            ListNode* t = head;
            head = next;
            next = next->next;
            head->next = t;
            --k;
        }
        prev->next = head;
        tail->next = NULL;
        return tail;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* begin = new ListNode(0);
        begin->next = head;
        ListNode* prev = begin;
        while (true) {
            int count = 0;
            while (head && count < k) {
                head = head->next;
                ++count;
            }
            if (count < k) {
                break;
            }
            prev = reverse(prev, k);
            prev->next = head;
        }
        return begin->next;
    }
};
