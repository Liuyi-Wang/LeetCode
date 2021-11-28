class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> result(n, -1);
        if (2*k+1 > n) {
            return result;
        }
        long long sum = 0;
        for (int i = 0; i < 2*k+1; ++i) {
            sum += nums[i];
        }
        for (int i = k; i < n-k; ++i) {
            result[i] = sum/(2*k+1);
            if (i == n-k-1) {
                break;
            }
            sum += nums[i+k+1];
            sum -= nums[i-k];
        }
        return result;
    }
};
