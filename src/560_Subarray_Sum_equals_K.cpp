class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int result = 0, sum = 0;
        unordered_map<int, int> hash;
        hash[0] = 1;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if (hash.find(sum-k) != hash.end()) {
                result += hash[sum-k];
            }
            ++hash[sum];
        }
        return result;
    }
};
