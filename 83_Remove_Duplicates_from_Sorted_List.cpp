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
        if (NULL == head) {
            return NULL;
        }
        ListNode *prev = head;
        ListNode *node = head->next;
        while (node) {
            if (prev->val != node->val) {
                prev->next = node;
                prev = node;
            }
            node = node->next;
        }
        prev->next = NULL;
        return head;
    }
};
