/**
 *  Time:
 *  O(n)
 *  Space:
 *  O(n)
 */
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        vector<int> v(n2, -1);
        stack<int> stk;
        stk.push(nums2.back());
        unordered_map<int, int> num2i;
        num2i[nums2.back()] = n2-1;
        for (int i = n2-2; i >= 0; --i) {
            num2i[nums2[i]] = i;
            while (!stk.empty() && stk.top() < nums2[i]) {
                stk.pop();
            }
            if (!stk.empty()) {
                v[i] = stk.top();
            }
            stk.push(nums2[i]);
        }
        vector<int> result(n1, -1);
        for (int i = 0; i < n1; ++i) {
            result[i] = v[num2i[nums1[i]]];
        }
        return result;
    }
};
