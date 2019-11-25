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
    ListNode* partition(ListNode* head, int x) {
        ListNode *lb = new ListNode(0);
        ListNode *le = lb;
        ListNode *rb = new ListNode(0);
        ListNode *re = rb;
        while (head) {
            if (head->val < x) {
                le->next = head;
                le = le->next;
            } else {
                re->next = head;
                re = re->next;
            }
            head = head->next;
        }
        if (!lb->next) {
            return rb->next;
        }
        if (!rb->next) {
            return lb->next;
        }
        le->next = rb->next;
        re->next = NULL;
        return lb->next;
    }
};
