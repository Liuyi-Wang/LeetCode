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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *solve(ListNode *head, ListNode *tail) {
        if (head == tail) {
            return NULL;
        }
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != tail && fast->next != tail) {
            fast = fast->next->next;
            slow = slow->next;
        }
        TreeNode *node = new TreeNode(slow->val);
        node->left = solve(head, slow);
        node->right = solve(slow->next, tail);
        return node;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        return solve(head, NULL);
    }
};
