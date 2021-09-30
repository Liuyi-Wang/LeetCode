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
    vector<int> nextLargerNodes(ListNode* head) {
        stack<pair<int, int>> s;
        vector<int> result;
        int index = 0;
        while (NULL != head) {
            result.push_back(0);
            while (!s.empty() && s.top().second < head->val) {
                pair<int, int> p = s.top();
                s.pop();
                result[p.first] = head->val;
            }
            s.push(pair<int, int>(index, head->val));
            ++index;
            head = head->next;
        }
        return result;
    }
};
