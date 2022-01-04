/**
 *  Time:
 *  O(n), to scan through nums
 *  O(nlogn), to sort
 *  O(n), to dp
 *  Space:
 *  O(n)+hashtable
 *  Can compress dp
 */
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int, int> count;
        vector<int> v;
        for (auto num:nums) {
            if (count.find(num) == count.end()) {
                count[num] = 1;
                v.push_back(num);
            } else {
                ++count[num];
            }
        }
        if (v.size() == 1) {
            return v[0]*count[v[0]];
        }
        sort(v.begin(), v.end());
        int n = v.size();
        vector<int> dp(n, 0);
        dp[0] = v[0]*count[v[0]];
        if (v[1] == v[0]+1) {
            dp[1] = max(v[1]*count[v[1]], dp[0]);
        } else {
            dp[1] = dp[0]+v[1]*count[v[1]];
        }
        for (int i = 2; i < n; ++i) {
            if (v[i] == v[i-1]+1) {
                dp[i] = max(dp[i-2]+v[i]*count[v[i]], dp[i-1]);
            } else {
                dp[i] = dp[i-1]+v[i]*count[v[i]];
            }
        }
        return dp.back();
    }
};
