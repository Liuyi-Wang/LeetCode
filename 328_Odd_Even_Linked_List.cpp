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
    ListNode* oddEvenList(ListNode* head) {
        int i = 1;
        ListNode* odd = new ListNode(0);
        ListNode* o = odd;
        ListNode* even = new ListNode(0);
        ListNode* e = even;
        while (head) {
            ListNode* next = head->next;
            head->next = NULL;
            if (1 == i%2) {
                o->next = head;
                o = head;
            } else {
                e->next = head;
                e = head;
            }
            head = next;
            ++i;
        }
        o->next = even->next;
        return odd->next;
    }
};
