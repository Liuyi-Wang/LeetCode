class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int num = INT_MAX;
        int sum = 0;
        for (auto n:nums) {
            sum += n;
            num = min(num, sum);
        }
        return max(1-num, 1);
    }
};
