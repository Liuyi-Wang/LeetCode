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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *result = new ListNode(0);
        result->next = head;
        ListNode *prev = result;
        for (int i = 0; i < m-1; ++i) {
            prev = prev->next;
        }
        ListNode *end = prev->next;
        head = prev->next;
        ListNode *node = head->next;
        for (int i = 0; i < n-m; ++i) {
            ListNode *next = node->next;
            node->next = head;
            head = node;
            node = next;
        }
        prev->next = head;
        end->next = node;
        return result->next;
    }
};
