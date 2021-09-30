class Solution {
public:
    int maxVowels(string s, int k) {
        int count = 0;
        if (k >= s.size()) {
            for (auto c:s) {
                if ('a' == c || 'e' == c || 'i' == c || 'o' == c || 'u' == c) {
                    ++count;
                }
            }
            return count;
        }
        int l = 0, r = l+k-1;
        for (int i = 0; i <= r; ++i) {
            char c = s[i];
            if ('a' == c || 'e' == c || 'i' == c || 'o' == c || 'u' == c) {
                ++count;
            }
        }
        int result = count;
        while (r+1 < s.size()) {
            char c = s[l++];
            if ('a' == c || 'e' == c || 'i' == c || 'o' == c || 'u' == c) {
                --count;
            }
            c = s[++r];
            if ('a' == c || 'e' == c || 'i' == c || 'o' == c || 'u' == c) {
                ++count;
            }
            if (count == k) {
                return k;
            }
            result = max(result, count);
        }
        return result;
    }
};
