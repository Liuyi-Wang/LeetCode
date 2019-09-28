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
     ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (NULL == l1) {
            return l2;
        }
        if (NULL == l2) {
            return l1;
        }
        if (l1->val <= l2->val) {
            ListNode* l = l1->next;
            l1->next = mergeTwoLists(l, l2);
            return l1;
        } else {
            ListNode* l = l2->next;
            l2->next = mergeTwoLists(l1, l);
            return l2;
        }
        return NULL;
    }
    
    ListNode* merge(const vector<ListNode*>& lists, int begin, int end) {
        if (begin == end) {
            return lists[begin];
        }
        int mid = begin+(end-begin)/2;
        ListNode* l1 = merge(lists, begin, mid);
        ListNode* l2 = merge(lists, mid+1, end);
        return mergeTwoLists(l1, l2);
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) {
            return NULL;
        }
        return merge(lists, 0, lists.size()-1);
    }
};
