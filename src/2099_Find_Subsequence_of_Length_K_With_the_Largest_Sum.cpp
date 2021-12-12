/**
 *  Time:
 *  O(n)
 *  Space:
 *  O(n)
 */
class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> heap;
        unordered_map<int, int> count;
        for (auto num:nums) {
            if (heap.size() < k) {
                heap.push(num);
                ++count[num];
            } else if (heap.top() < num) {
                --count[heap.top()];
                heap.pop();
                heap.push(num);
                ++count[num];
            }
        }
        vector<int> result;
        for (auto num:nums) {
            if (count[num] > 0) {
                --count[num];
                result.push_back(num);
            }
            if (result.size() == k) {
                break;
            }
        }
        return result;
    }
};
