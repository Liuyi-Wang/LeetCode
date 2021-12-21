/**
 *  Time:
 *  O(1)
 *  Space:
 *  O(1)
 */
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n == 0) {
            return false;
        }
        long long l = n;
        return (l & (l-1)) == 0;
    }
};
