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
    void reorderList(ListNode *head) {
        if (NULL == head || NULL == head->next || NULL == head->next->next) {
            return;
        }
        ListNode *slow = head, *fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = slow->next;
        slow->next = NULL;
        stack<ListNode*> s;
        while (fast) {
            s.push(fast);
            fast = fast->next;
        }
        slow = head;
        ListNode *tail = NULL;
        while (!s.empty()) {
            fast = slow->next;
            slow->next = s.top();
            s.top()->next = fast;
            tail = s.top();
            s.pop();
            slow = fast;
        }
        tail->next = slow;
    }
};
