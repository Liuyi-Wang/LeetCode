/**
 *  Time:
 *  O(nn)
 *  Space:
 *  O(1)
 */
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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* begin = new ListNode();
        while (head) {
            ListNode* next = head->next;
            head->next = NULL;
            ListNode* node = begin;
            while (node->next && node->next->val < head->val) {
                node = node->next;
            }
            head->next = node->next;
            node->next = head;
            head = next;
        }
        return begin->next;
    }
};
