class Solution {
public:
    string removeOuterParentheses(string S) {
        int count = 0;
        string result;
        for (auto c:S) {
            if ('(' == c) {
                ++count;
                if (1 != count) {
                    result += c;
                }
            } else {
                --count;
                if (0 != count) {
                    result += c;
                }
            }
        }
        return result;
    }
};
