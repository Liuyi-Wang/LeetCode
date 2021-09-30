class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        bool b12 = true, b21 = true;
        for (int i = 0; i < s1.size(); ++i) {
            if (!b21 && !b12) {
                return false;
            }
            if (s1[i] > s2[i]) {
                b21 = false;
            } else if (s1[i] < s2[i]) {
                b12 = false;
            }
        }
        return b21 || b12;
    }
};
