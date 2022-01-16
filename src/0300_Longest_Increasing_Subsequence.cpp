/**
 *  Time:
 *  O(nlogn)
 *  Space:
 *  O(n)
 *  dp
 *  Time:
 *  O(nn)
 *  Space:
 *  O(n)
 */
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        return dp(nums);
    }
    
    int dp(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        int result = 1;
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
            result = max(result, dp[i]);
        }
        return result;
    }
    
    int sol2(vector<int>& nums) {
        vector<int> lis;
        lis.push_back(nums[0]);
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > lis.back()) {
                lis.push_back(nums[i]);
                continue;
            }
            int j = lower_bound(lis.begin(), lis.end(), nums[i]) - lis.begin();
            lis[j] = nums[i];
        }
        return lis.size();
    }
};
