/**
 *  Time:
 *  O(n)
 *  Space:
 *  O(1)
 */
class Solution {
public:
    string decodeString(string s) {
        int i = 0;
        int n = s.size();
        string result;
        while (i < n) {
            if (isdigit(s[i])) {
                int begin = i;
                while (i+1 < n && isdigit(s[i+1])) {
                    ++i;
                }
                int count = stoi(s.substr(begin, i-begin+1));
                
                i += 2;
                begin = i;
                int l = 1;
                while (i < n) {
                    if (s[i] == '[') {
                        ++l;
                    } else if (s[i] == ']') {
                        --l;
                    }
                    if (l == 0) {
                        break;
                    }
                    ++i;
                }
                int end = i-1;
                string t = decodeString(s.substr(begin, end-begin+1));
                for (int c = 0; c < count; ++c) {
                    result += t;
                }
                ++i;
            } else {
                int begin = i;
                while (i+1 < n && !isdigit(s[i+1])) {
                    ++i;
                }
                result += s.substr(begin, i-begin+1);
                ++i;
            }
        }
        return result;
    }
};
