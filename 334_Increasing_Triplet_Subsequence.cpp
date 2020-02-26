class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int a = INT_MAX, b = INT_MAX;
        for (auto n:nums) {
            if (n > b) {
                return true;
            }
            if (n > a) {
                b = n;
            } else {
                a = n;
            }
        }
        return false;
    }
};
