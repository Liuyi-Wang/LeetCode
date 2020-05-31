class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int first = 0, second = 1;
        if (nums[0] < nums[1]) {
            first = 1;
            second = 0;
        }
        for (int i = 2; i < nums.size(); ++i) {
            if (nums[i] >= nums[first]) {
                second = first;
                first = i;
            } else if (nums[i] >= nums[second]) {
                second = i;
            }
        }
        return (nums[first]-1)*(nums[second]-1);
    }
};
