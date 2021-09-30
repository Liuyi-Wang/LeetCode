class Solution {
public:
    Solution(vector<int>& nums) {
        d_nums = nums;
    }
    
    int pick(int target) {
        int result = -1, count = 0;
        for (int i = 0; i < d_nums.size(); ++i) {
            if (d_nums[i] != target) {
                continue;
            }
            ++count;
            if (rand()%count == 0) {
                result = i;
            }
        }
        return result;
    }
    
private:
    vector<int> d_nums;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
