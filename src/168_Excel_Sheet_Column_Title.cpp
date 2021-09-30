class Solution {
public:
    string convertToTitle(int n) {
        string result;
        while (n >= 1) {
            --n;
            string s = "A";
            s[0] += n%26;
            result = s+result;
            n /= 26;
        }
        return result;
    }
};
