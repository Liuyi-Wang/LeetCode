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
    int numComponents(ListNode* head, vector<int>& G) {
        vector<bool> hash(10000, false);
        for (auto g:G) {
            hash[g] = true;
        }
        int result = 0;
        bool connected = false;
        while (head) {
            if (!hash[head->val]) {
                if (connected) {
                    ++result;
                }
                connected = false;
            } else {
                connected = true;
            }
            head = head->next;
        }
        if (connected) {
            ++result;
        }
        return result;
    }
};
