class Solution {
public:
    int myAtoi(string str) {
        long long n = 0;
        int index = 0;
        bool prefix = true;
        int sign = 1;
        while (index < str.size()) {
            if (prefix && ' ' == str[index]) {
                ++index;
                continue;
            }
            if (prefix && '+' == str[index]) {
                ++index;
                prefix = false;
                continue;
            } else if (prefix && '-' == str[index]) {
                sign = -1;
                ++index;
                prefix = false;
                continue;
            }
            prefix = false;
            if (!isdigit(str[index])) {
                break;
            }
            n = n*10+(str[index]-'0');
            if (sign*n > INT_MAX) {
                return INT_MAX;
            } else if (sign*n < INT_MIN) {
                return INT_MIN;
            }
            ++index;
        }
        return sign*n;
    }
};
