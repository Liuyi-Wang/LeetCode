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
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        int l = 2;
        ListNode* node = head;
        int len = 0;
        while (node) {
            ++len;
            node = node->next;
        }
        node = head;
        --len;
        while (node) {
            //cout << len << endl;
            if (len < l) {
                if (len%2 == 0) {
                    node = reverse(node, len);
                }
                break;
            }
            if (l%2 == 1) {
                int n = 0;
                while (node && n < l) {
                    node = node->next;
                    ++n;
                }
            } else {
                node = reverse(node, l);
            }
            len -= l;
            ++l;
        }
        return head;
    }
    
    ListNode* reverse(ListNode* head, int l) {
        //cout << head->val << "," << l << endl;
        if (!head) {
            return head;
        }
        ListNode* node = head->next;
        if (!node) {
            return node;
        }
        int n = 0;
        stack<ListNode*> stk;
        while (node && n < l) {
            stk.push(node);
            node = node->next;
            ++n;
        }
        ListNode* begin = stk.top();
        ListNode* end = begin;
        stk.pop();
        while (!stk.empty()) {
            end->next = stk.top();
            stk.pop();
            end = end->next;
        }
        head->next = begin;
        end->next = node;
        return end;
    }
};
