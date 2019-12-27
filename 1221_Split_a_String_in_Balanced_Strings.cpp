class Solution {
public:
    int balancedStringSplit(string s) {
        int b = 0;
        int result = 0;
        for (auto c:s) {
            if ('L' == c) {
                ++b;
            } else {
                --b;
            }
            result += 0==b?1:0;
        }
        return result;
    }
};
