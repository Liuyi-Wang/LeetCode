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
    ListNode* insertionSortList(ListNode* head) {
        if (NULL == head || NULL == head->next) {
            return head;
        }
        ListNode *result = new ListNode(0); 
        result->next = head;
        head = head->next;
        result->next->next = NULL;
        while (head) {
            ListNode *next = head->next;
            head->next = NULL;
            ListNode *temp = result;
            while (temp->next && temp->next->val < head->val) {
                temp = temp->next;
            }
            head->next = temp->next;
            temp->next = head;
            head = next;
        }
        return result->next;
    }
};
