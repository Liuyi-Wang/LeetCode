class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        if (0 == k) {
            return;
        }
        int count = 0;
        int begin = 0;
        int i = 0;
        int last = nums[i];
        while (count++ < nums.size()) {
            i = (i+k)%nums.size();
            int t = nums[i];
            nums[i] = last;
            if (i == begin) {
                ++begin;
                i = begin;
                last = nums[i];
            } else {
                last = t;
            }
        }
    }
};
