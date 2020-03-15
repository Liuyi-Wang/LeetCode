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
    int solve(ListNode* head) {
        if (NULL == head->next) {
            int sum = head->val+1;
            head->val = sum%10;
            return sum/10;
        }
        int carry = solve(head->next);
        int sum = head->val+carry;
        head->val = sum%10;
        return sum/10;
    }
    
    ListNode* plusOne(ListNode* head) {
        int carry = solve(head);
        if (carry) {
            ListNode* result = new ListNode(1);
            result->next = head;
            return result;
        }
        return head;
    }
};
