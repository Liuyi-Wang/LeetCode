/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int len(ListNode *l) {
        int s = 0;
        while (l) {
            ++s;
            l = l->next;
        }
        return s;
    }
    
    int solve(ListNode *l1, ListNode *l2) {
        if (l1 && l2) {
            int c = solve(l1->next, l2->next);
            int sum = c+l1->val+l2->val;
            l1->val = sum%10;
            return sum/10;
        }
        return 0;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int len1 = len(l1);
        int len2 = len(l2);
        if (len1 < len2) {
            ListNode *l = l1;
            l1 = l2;
            l2 = l;
            int t = len1;
            len1 = len2;
            len2 = t;
        }
        ListNode *head = new ListNode(0);
        ListNode *tail = head;
        while (len2 < len1) {
            ++len2;
            tail->next = new ListNode(0);
            tail = tail->next;
        }
        tail->next = l2;
        l2 = head->next;
        int c = solve(l1, l2);
        if (1 == c) {
            ListNode *result = new ListNode(1);
            result->next = l1;
            return result;
        }
        return l1;
    } 
};
