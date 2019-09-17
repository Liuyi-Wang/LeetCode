class Solution {
public:
    int brokenCalc(int X, int Y) {
        int result = 0;
        while (X != Y) {
            if (X >= Y) {
                return X-Y+result;
            }
            if (0 == Y%2) {
                Y /= 2;
            } else {
                ++Y;
            }
            ++result;
        }
        return result;
    }
};
