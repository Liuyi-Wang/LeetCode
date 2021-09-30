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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        ListNode* head = root;
        int len = 0;
        while (head) {
            ++len;
            head = head->next;
        }
        int n = len/k;
        int m = len%k;
        k -= m;
        vector<ListNode*> result;
        for (; m >= 1; --m) {
            head = root;
            len = 1;
            while (len < n+1) {
                head = head->next;
                ++len;
            }
            ListNode* next = head->next;
            head->next = NULL;
            result.push_back(root);
            root = next;
        }
        if (0 == n) {
            for (; k >= 1; --k) {
                result.push_back(NULL);
            }
        } else {
            for (; k >= 1; --k) {
                head = root;
                len = 1;
                while (len < n) {
                    head = head->next;
                    ++len;
                }
                ListNode* next = head->next;
                head->next = NULL;
                result.push_back(root);
                root = next;
            }
        }
        return result;
    }
};
