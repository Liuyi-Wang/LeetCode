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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *result = new ListNode(0);
        result->next = head;
        ListNode *prev = result;
        ListNode *node = prev->next;
        while (node && node->next) {
            if (node->val != node->next->val) {
                prev->next = node;
                prev = node;
                node = node->next;
                continue;
            }
            while (node->next && node->next->val == node->val) {
                node = node->next;
            }
            node = node->next;
        }
        if (node) {
            prev->next = node;
            prev = node;
        }
        prev->next = NULL;
        return result->next;
    }
};
