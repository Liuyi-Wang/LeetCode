class Solution {
public:
    bool isNumber(string s) {
        int i = 0;
        // Heading space
        while (i < s.size()) {
            if (' ' == s[i]) {
                ++i;
            } else {
                break;
            }
        }
        bool sign = true;
        bool dot = false;
        bool e = false;
        bool zero = false;
        bool num = false;
        while (i < s.size()) {
            if ('.' == s[i]) {
                if (dot) {
                    return false;
                }
                if (e) {
                    return false;
                }
                dot = true;
                sign = false;
            } else if ('e' == s[i]) {
                if (e) {
                    return false;
                }
                if (!num) {
                    return false;
                }
                e = true;
                sign = true;
                num = false;
            } else if ('+' == s[i] || '-' == s[i]) {
                if (!sign) {
                    return false;
                }
                sign = false;
            } else if ('0' <= s[i] && s[i] <= '9') {
                num = true;
                sign = false;
            } else if (' ' == s[i]) {
                break;
            } else {
                return false;
            }
            ++i;
        }
        if (!num) {
            return false;
        }
        // Tailing space
        while (i < s.size()) {
            if (' ' == s[i]) {
                ++i;
            } else {
                return false;
            }
        }
        return true;
    }
};
