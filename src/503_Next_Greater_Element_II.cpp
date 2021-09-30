class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        if (0 == nums.size()) {
            return {};
        }
        stack<int> s;
        s.push(nums.back());
        for (int i = nums.size()-2; i >= 0; --i) {
            while (!s.empty() && s.top() <= nums[i]) {
                s.pop();
            }
            s.push(nums[i]);   
        }
        vector<int> result(nums.size(), -1);
        for (int i = nums.size()-1; i >= 0; --i) {
            while (!s.empty() && s.top() <= nums[i]) {
                s.pop();
            }
            if (!s.empty()) {
                result[i] = s.top();
            }
            s.push(nums[i]);
        }
        return result;
    }
};
