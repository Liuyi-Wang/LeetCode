class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        return max(scan(answerKey, k, 'T'), scan(answerKey, k, 'F'));
    }
    
    int scan(const string& answerKey, int k, char c) {
        int n = answerKey.size();
        int l = 0, r = 0, m = 0;
        int result = 0;
        while (r < n) {
            while (r < n && (answerKey[r] == c || (answerKey[r] != c && m < k))) {
                if (answerKey[r] != c ) {
                    ++m;
                }
                ++r;
            }
            result = max(result, r-1-l+1);
            if (r == n) {
                break;
            }
            while (l < r && answerKey[l] == c) {
                ++l;
            }
            ++l;
            --m;
        }
        return result;
    }
};
