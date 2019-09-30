class Solution {
public:
    char findTheDifference(string s, string t) {
        char result = 0;
        for (const auto c:s) {
            result ^= c;
        }
        for (const auto c:t) {
            result ^= c;
        }
        return result;
    }
};
