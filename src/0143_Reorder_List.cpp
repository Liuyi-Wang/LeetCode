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
    void reorderList(ListNode* head) {
        if (head->next == NULL || head->next->next == NULL) {
            return;
        }
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = slow->next;
        slow->next = NULL;
        slow = new ListNode();
        while (fast) {
            ListNode* next = fast->next;
            fast->next = slow->next;
            slow->next = fast;
            fast = next;
        }
        slow = slow->next;
        fast = head; 
        ListNode* begin = new ListNode();
        ListNode* end = begin;
        while (slow) {
            ListNode* nexts = slow->next;
            ListNode* nextf = fast->next;
            end->next = fast;
            fast->next = slow;
            slow->next = NULL;
            end = slow;
            fast = nextf;
            slow = nexts;
        }
        if (fast) {
            end->next = fast;
        }
        head = begin->next;
        return;
    }
};
