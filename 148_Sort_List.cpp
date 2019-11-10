static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (NULL == l1) {
            return l2;
        }
        if (NULL == l2) {
            return l1;
        }
        if (l1->val <= l2->val) {
            ListNode* l = l1->next;
            l1->next = mergeTwoLists(l, l2);
            return l1;
        } else {
            ListNode* l = l2->next;
            l2->next = mergeTwoLists(l1, l);
            return l2;
        }
        return NULL;
    }
    
    ListNode* sortList(ListNode* head) {
        if (NULL == head) {
            return NULL;
        }    
        if (NULL == head->next) {
            return head;
        }
        ListNode* fast = head->next;
        ListNode* slow = head;
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* second = slow->next;
        slow->next = NULL;
        head = sortList(head);
        second = sortList(second);
        return mergeTwoLists(head, second);    
    }
};
