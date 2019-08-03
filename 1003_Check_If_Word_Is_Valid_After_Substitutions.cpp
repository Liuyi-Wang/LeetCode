class Solution {
public:
    bool isValid(string S) {
        int a_c = 0, b_c = 0, c_c = 0;
        for (auto s:S) {
            if ('a' == s) {
                ++a_c;
            } else if ('b' == s) {
                ++b_c;
            } else if ('c' == s) {
                ++c_c;
            }
        }
        stack<char> c;
        char c1 = 'x', c2 = 'x';
        for (int i = 0; i < S.size(); ++i) {
            if ('x' == c1) {
                c1 = S[i];
                continue;
            }
            if ('x' == c2) {
                c2 = S[i];
                continue;
            }
            if ('a' == c1 && 'b' == c2 && 'c' == S[i]) {
                if (0 == c.size()) {
                    c1 = 'x';
                    c2 = 'x';
                } else if (1 == c.size()) {
                    c1 = c.top();
                    c.pop();
                    c2 = 'x';
                } else {
                    c2 = c.top();
                    c.pop();
                    c1 = c.top();
                    c.pop();
                }
                continue;
            }
            if (c1 != 'x') {
                c.push(c1);
            }
            c1 = c2;
            c2 = S[i];
        }
        if (c1 != 'x' || c2 != 'x') {
            return false;
        }
        return c.empty();
    }
};
