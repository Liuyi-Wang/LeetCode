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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* begin = new ListNode();
        begin->next = head;
        ListNode* prev = begin;
        while (head) {
            if (head->val == val) {
                prev->next = head->next;
                head = head->next;
            } else {
                prev = head;
                head = head->next;
            }
        }
        return begin->next;
    }
};
