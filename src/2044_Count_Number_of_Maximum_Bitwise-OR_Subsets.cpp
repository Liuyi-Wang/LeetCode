class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        d_target = 0;
        for (auto num:nums) {
            d_target = (d_target|num);
        }
        d_count = 0;
        //cout << d_target << endl;
        count(nums, 0, 0);
        return d_count;
    }
    
    void count(const vector<int>& nums, int i, int n) {
        if (i == nums.size()) {
            return;
        }
        if ((n|nums[i]) == d_target) {
            ++d_count;
        }
        count(nums, i+1, n|nums[i]);
        count(nums, i+1, n);
    }
    
private:
    int d_target;
    int d_count;
};
