/**
 *  Time:
 *  O(n)
 *  Space:
 *  O(1)
 */
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                continue;
            }
            int j = nums[i];
            while (nums[j-1] != 0) {
                int t = nums[j-1];
                nums[j-1] = 0;
                j = t;
            }
        }
        vector<int> result;
        for (int i = 0; i < n; ++i) {
            if (nums[i] != 0) {
                result.push_back(i+1);
            }
        }
        return result;
    }
};
