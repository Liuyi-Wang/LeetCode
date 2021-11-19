/**
 *  Time:
 *  O(1)
 *  Space:
 *  O(1)
 */
class Solution {
public:
    int hammingDistance(int x, int y) {
        int result = 0;
        int x_or = x^y;
        while (x_or) {
            ++result;
            x_or = x_or&(x_or-1);
        }
        return result;
    }
};
