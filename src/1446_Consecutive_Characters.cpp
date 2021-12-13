/**
 *  Time:
 *  O(n)
 *  Space:
 *  O(1)
 */
class Solution {
public:
    int maxPower(string s) {
        int result = 0;
        for (int i = 0; i < s.size();) {
            int l = 1;
            while (i+1 < s.size() && s[i] == s[i+1]) {
                ++l;
                ++i;
            }
            result = max(result, l);
            ++i;
        }
        return result;
    }
};
