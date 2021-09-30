class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (0 == n) {
            return 1;
        }
        int result = 10;
        int p = 9;
        int c = 9;
        for (int i = 1; i < n; ++i) {
            p *= c--;
            result += p;
        }
        return result;
    }
};
