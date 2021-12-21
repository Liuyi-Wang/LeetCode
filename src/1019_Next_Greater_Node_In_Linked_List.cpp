/**
 *  Time:
 *  O(n)
 *  Space:
 *  O(n)
 */
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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> nums;
        while (head) {
            nums.push_back(head->val);
            head = head->next;
        }
        vector<int> result(nums.size(), 0);
        stack<int> stk;
        for (int i = 0; i < nums.size(); ++i) {
            while (!stk.empty() && nums[stk.top()] < nums[i]) {
                result[stk.top()] = nums[i];
                stk.pop();
            }
            stk.push(i);
        }
        return result;
    }
};
