class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int l = -1;
        for (int i = 0; i < nums.size(); ++i) {
            if (1 == nums[i]) {
                l = i;
                break;
            }
        }
        if (-1 == l) {
            return true;
        }
        int r = l;
        for (int i = l+1; i < nums.size(); ++i) {
            if (1 == nums[i]) {
                r = i;
                break;
            }
        }
        if (r == l) {
            return true;
        }
        while (r < nums.size()) {
            if (r-l-1 < k) {
                return false;
            }
            int n = r;
            for (int i = r+1; i < nums.size(); ++i) {
                if (1 == nums[i]) {
                    n = i;
                    break;
                }
            }
            if (n == r) {
                return true;
            }
            l = r;
            r = n;
        }
        return true;
    }
};
