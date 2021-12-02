/**
 *  Time:
 *  O(n)
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
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL || head->next == NULL || head->next->next == NULL) {
            return head;
        }
        ListNode* oddHead = head, *oddTail = head;
        ListNode* evenHead = head->next, *evenTail = head->next;
        int count = 1;
        head = head->next->next;
        oddTail->next = NULL;
        evenTail->next = NULL;
        while (head) {
            if (count%2 == 1) {
                ListNode* next = head->next;
                head->next = NULL;
                oddTail->next = head;
                oddTail = oddTail->next;
                head = next;
            } else {
                ListNode* next = head->next;
                head->next = NULL;
                evenTail->next = head;
                evenTail = evenTail->next;
                head = next;
            }
            ++count;
        }
        oddTail->next = evenHead;
        return oddHead;
    }
};
