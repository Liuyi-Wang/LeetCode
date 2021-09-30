class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int result = 1;
        int l = 0, r = 1;
        deque<int> mx;
        deque<int> mn;
        mx.push_back(nums[l]);
        mn.push_back(nums[l]);
        while (r < nums.size()) {
            if ((!mx.empty() && abs(nums[r]-mx.front()) <= limit) && (!mn.empty() && abs(nums[r]-mn.front()) <= limit)) {
                result = max(result, r-l+1);
                while (!mx.empty() && mx.back() < nums[r]) {
                    mx.pop_back();
                }
                mx.push_back(nums[r]);
                while (!mn.empty() && mn.back() > nums[r]) {
                    mn.pop_back();
                }
                mn.push_back(nums[r]);
                ++r;
                continue;
            }
            //cout << l << "===" << r << endl;
            while ((!mx.empty() && abs(nums[r]-mx.front()) > limit) || (!mn.empty() && abs(nums[r]-mn.front()) > limit)) {
                if (!mx.empty() && mx.front() == nums[l]) {
                    mx.pop_front();
                }
                if (!mn.empty() && mn.front() == nums[l]) {
                    mn.pop_front();
                }
                ++l;
                if (l == r) {
                    break;
                }
            }
            while (!mx.empty() && mx.back() < nums[r]) {
                mx.pop_back();
            }
            mx.push_back(nums[r]);
            while (!mn.empty() && mn.back() > nums[r]) {
                mn.pop_back();
            }
            mn.push_back(nums[r]);
            ++r;
        }
        return result;
    }
};
