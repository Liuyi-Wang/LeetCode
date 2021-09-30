class Solution {
public:
    int climbStairs(int n) {
        if (1 == n) {
            return 1;
        }
        if (2 == n) {
            return 2;
        }
        int n1 = 1, n2 =2;
        int result;
        for (int i = 3; i <= n; ++i) {
            result = n1+n2;
            n1 = n2;
            n2 = result;
        }
        return result;
    }
};
