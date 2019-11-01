class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long first = LONG_MIN, second = LONG_MIN, third = LONG_MIN;
        int count = 0;
        for (auto n:nums) {
            if (first == n || second == n || third == n) {
                continue;
            }
            if (n >= first) {
                third = second;
                second = first;
                first = n;
                ++count;
            } else if (n >= second) {
                third = second;
                second = n;
                ++count;
            } else if (n >= third) {
                third = n;
                ++count;
            }
        }
        if (count >= 3) {
            return third;
        }    
        return first;
    }
};
