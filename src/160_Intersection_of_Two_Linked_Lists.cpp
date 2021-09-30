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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *a = headA, *b = headB;
        while (NULL != a && NULL != b) {
            if (a == b) {
                return a;
            }
            a = a->next;
            b = b->next;
            if (NULL == a && NULL == b) {
                return NULL;
            }
            if (NULL == a) {
                a = headB;
            }
            if (NULL == b) {
                b = headA;
            }
        }
        return NULL;
    }
};
