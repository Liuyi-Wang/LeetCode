class Solution {
public:
    bool sumGame(string num) {
        int lc = 0, ls = 0, rc = 0, rs = 0;
        for (int i = 0; i < num.size()/2; ++i) {
            if (num[i] == '?') {
                ++lc;
            } else {
                ls += num[i]-'0';
            }
        }
        for (int i = num.size()/2; i < num.size(); ++i) {
            if (num[i] == '?') {
                ++rc;
            } else {
                rs += num[i]-'0';
            }
        }
        if ((lc+rc)%2 == 1) {
            return true;
        }
        if (lc == 0 && rc == 0) {
            return ls != rs;
        }
        int c = lc-rc, s = ls-rs;
        if (c*s > 0) {
            return true;
        }
        return abs(s) != 9*abs(c)/2;
    }
};
