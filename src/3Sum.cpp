class Solution {
public:
    void solve(const vector<int>& nums, int begin, vector<vector<int>>& result) {
    }
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        for (int begin = 0; begin < nums.size();) {
            int sum = -nums[begin];
            int head = begin+1, tail = nums.size()-1;
            while (head < tail) {
                if (nums[head]+nums[tail] == sum) {
                    vector<int> triplet;
                    triplet.push_back(nums[begin]);
                    triplet.push_back(nums[head]);
                    triplet.push_back(nums[tail]);
                    result.push_back(triplet);
                    ++head;
                    while (head < tail && nums[head] == nums[head-1]) {
                        ++head;
                    }
                    --tail;
                    while (head < tail && nums[tail] == nums[tail+1]) {
                        --tail;
                    }
                } else if (nums[head]+nums[tail] < sum) {
                    ++head;
                    while (head < tail && nums[head] == nums[head-1]) {
                        ++head;
                    }
                } else {
                    --tail;
                    while (head < tail && nums[tail] == nums[tail+1]) {
                        --tail;
                    }
                }
            }
            ++begin;
            while (begin < nums.size() && nums[begin] == nums[begin-1]) {
                ++begin;
            }
        }
        return result;
    }
};
