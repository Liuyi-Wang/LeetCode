class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char, int> counts;
        int odd = 0, even = 0;
        for (auto c:s) {
            ++counts[c];
            if (1 == counts[c]) {
                ++odd;
            } else if (0 == counts[c]%2) {
                --odd;
                ++even;
            } else {
                --even;
                ++odd;
            }
        }
        return odd <= 1;
    }
};
