/**
 *  Time:
 *  O(nn)
 *  Space:
 *  O(nn)
 */
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dpMax(n, vector<int>(n, INT_MIN));
        vector<vector<int>> dpMin(n, vector<int>(n, INT_MAX));
        for (int i = 0; i < n; ++i) {
            dpMax[i][i] = nums[i];
            dpMin[i][i] = nums[i];
        }
        long long result = 0;
        for (int l = 2; l <= n; ++l) {
            for (int i = 0; i+l-1 < n; ++i) {
                int j = i+l-1;
                dpMax[i][j] = max(dpMax[i][j-1], nums[j]);
                dpMin[i][j] = min(dpMin[i][j-1], nums[j]);
                result += ((long long)dpMax[i][j]-(long long)dpMin[i][j]);
            }
        }
        return result;
    }
};
