class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        if (s.size() < t.size()) {
            string temp = s;
            s = t;
            t = temp;
        }
        if (s.size()-t.size() > 1) {
            return false;
        }
        if (s.size() == t.size()) {
            int diff = 0;
            for (int i = 0; i < s.size(); ++i) {
                if (s[i] != t[i]) {
                    ++diff;
                    if (diff > 1) {
                        return false;
                    }
                }
            }
            return diff == 1;
        }
        int is = 0, it = 0;
        bool diff = false;
        for (; is < s.size();) {
            if (s[is] == t[it]) {
                ++is;
                ++it;
                continue;
            }
            if (diff) {
                return false;
            }
            diff = true;
            ++is;
        }
        return true;
    }
};
