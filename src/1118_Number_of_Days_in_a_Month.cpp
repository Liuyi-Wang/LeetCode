class Solution {
public:
    int numberOfDays(int Y, int M) {
        if (1 == M || 3 == M || 5 == M || 7 == M || 8 == M || 10 == M || 12 == M) {
            return 31;
        }
        if (2 == M) {
            if (0==Y%400) {
                return 29;
            }
            if (0==Y%4 && 0!=Y%100) {
                return 29;
            }
            return 28;
        }
        return 30;
    }
};
