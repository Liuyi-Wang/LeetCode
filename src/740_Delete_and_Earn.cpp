/**
 *  Time Complexity:
 *  O(n), to scan through nums
 *  O(nlogn), to sort
 *  O(n), to dp
 *  Space Complexity:
 *  O(n)+hashtable
 *  Can compress dp
 */
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int, int> num2count;
        vector<int> v;
        for (auto num:nums) {
            ++num2count[num];
            if (num2count[num] == 1) {
                v.push_back(num);
            }
        }
        sort(v.begin(), v.end());
        int n = v.size();
        if (n == 1) {
            return v[0]*num2count[v[0]];
        }
        if (n == 2) {
            if (v[1] == v[0]+1) {
                return max(v[0]*num2count[v[0]], v[1]*num2count[v[1]]);
            } else {
                return v[1]*num2count[v[1]]+v[0]*num2count[v[0]];
            }
        }
        vector<int> dp(n, 0);
        dp[0] = v[0]*num2count[v[0]];
        if (v[1] == v[0]+1) {
            dp[1] = max(v[0]*num2count[v[0]], v[1]*num2count[v[1]]);
        } else {
            dp[1] = v[1]*num2count[v[1]]+v[0]*num2count[v[0]];
        }
        int result = max(dp[0], dp[1]);
        for (int i = 2; i < n; ++i) {
            if (v[i] == v[i-1]+1) {
                dp[i] = max(dp[i-1], v[i]*num2count[v[i]]+dp[i-2]);
            } else {
                dp[i] = v[i]*num2count[v[i]]+dp[i-1];
            }
            result = max(result, dp[i]);
        }
        return result;
    }
};
