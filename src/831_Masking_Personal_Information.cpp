class Solution {
public:
    string maskPII(string S) {
        string result;
        if (isalpha(S[0])) {
            result += tolower(S[0]);
            result += "*****";
            int i = 2;
            for (; i < S.size(); ++i) {
                if ('@' == S[i]) {
                    break;
                }
            }
            result += tolower(S[i-1]);
            result += '@';
            for (i += 1; i < S.size(); ++i) {
                result += tolower(S[i]);
            }
            return result;
        } else {
            int end = S.size()-1;
            int count = 4;
            for (; end >= 0 && count > 0; --end) {
                if (!isdigit(S[end])) {
                    continue;
                }
                result += S[end];
                --count;
            }
            result += "-***-***";
            count = 0;
            for (; end >= 0; --end) {
                if (isdigit(S[end])) {
                    ++count;
                }
            }
            if (count > 6) {
                string star(count-6, '*');
                result += '-';
                result += star;
                result += '+';
            }
            reverse(result.begin(), result.end());
            return result;
        }
    }
};
