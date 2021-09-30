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
    bool isPalindrome(ListNode* head) {
        stack<int> s;
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast && fast->next) {
            s.push(slow->val);
            slow = slow->next;
            fast = fast->next->next;
        }
        if (NULL != fast) {
            slow = slow->next;
        }
        while (slow) {
            if (slow->val != s.top()) {
                return false;
            }
            slow = slow->next;
            s.pop();
        }
        return true;
    }
};
