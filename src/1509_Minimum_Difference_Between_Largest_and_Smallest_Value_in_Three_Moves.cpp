class Solution {
public:
    int minDifference(vector<int>& nums) {
        if (nums.size() <= 4) {
            return 0;
        }
        int s1 = INT_MAX, s2 = INT_MAX, s3 = INT_MAX, s4 = INT_MAX;
        int l1 = INT_MIN, l2 = INT_MIN, l3 = INT_MIN, l4 = INT_MIN;
        for (auto num:nums) {
            if (num < s1) {
                s4 = s3;
                s3 = s2;
                s2 = s1;
                s1 = num;
            } else if (num < s2) {
                s4 = s3;
                s3 = s2;
                s2 = num;
            } else if (num < s3) {
                s4 = s3;
                s3 = num;
            } else if (num < s4) {
                s4 = num;
            }
            if (num > l1) {
                l4 = l3;
                l3 = l2;
                l2 = l1;
                l1 = num;
            } else if (num > l2) {
                l4 = l3;
                l3 = l2;
                l2 = num;
            } else if (num > l3) {
                l4 = l3;
                l3 = num;
            } else if (num > l4) {
                l4 = num;
            }
        }
        int result = l4-s1;
        result = min(result, l3-s2);
        result = min(result, l2-s3);
        return min(result, l1-s4);
    }
};
