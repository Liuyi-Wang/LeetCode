class Solution {
public:
    int maxPower(string s) {
        int result = 0;
        int len = 1;
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == s[i-1]) {
                ++len;
            } else {
                result = max(result, len);
                len = 1;
            }
        }
        return max(result, len);
    }
};
