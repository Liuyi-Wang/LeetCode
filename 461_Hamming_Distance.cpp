class Solution {
public:
    int hammingDistance(int x, int y) {
        x ^= y;
        int result = 0;
        while (x) {
            ++result;
            x = (x&(x-1));
        }
        return result;
    }
};
