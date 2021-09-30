class Solution {
public:
    int next(const vector<int> &nums, int i) {
        return (i+nums[i]+nums.size())%nums.size();
    }
    
    bool circularArrayLoop(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            if (0 == nums[i]) {
                continue;
            }
            int slow = i, fast = next(nums, i);
            while (nums[i]*nums[fast] > 0 && nums[i]*nums[next(nums, fast)] > 0) {
                if (slow == fast) {
                    if (next(nums, slow) == slow) {
                        break;
                    }
                    return true;
                }
                slow = next(nums, slow);
                fast = next(nums, next(nums, fast));
            }
            slow = i;
            int n = nums[i];
            while (n*nums[slow] > 0) {
                int j = slow;
                slow = next(nums, slow);
                nums[j] = 0;
            }
        }
        return false;
    }
};
