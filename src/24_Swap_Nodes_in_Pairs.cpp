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
    ListNode* swapPairs(ListNode* head) {
        ListNode* begin = new ListNode(0);
        begin->next = head;
        ListNode* pre = begin;
        while (head && head->next) {
            ListNode* first = head;
            ListNode* second = head->next;
            head = second->next;
            pre->next = second;
            second->next = first;
            first->next = head;
            pre = first;
        }
        return begin->next;
    }
};
