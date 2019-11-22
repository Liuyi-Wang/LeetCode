class Solution {
public:
    string getPermutation(int n, int k) { 
        int N = 1;
        for (int i = n; i >= 1; --i) {
            N *= i;
        }
        string result;
        string digits;
        for (int i = 0; i < n; ++i) {
            digits += '1'+i;
        }
        --k;
        for (int i = n; i > 1; --i) {
            int s = N/i;
            result += digits[k/s];
            digits.erase(k/s, 1);
            k %= s;
            N /= i;
        }
        result += digits.back();
        return result;
    }
};
