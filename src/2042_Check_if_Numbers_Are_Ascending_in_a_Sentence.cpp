class Solution {
public:
    bool areNumbersAscending(string s) {
        int i = 0, n = s.size();
        int last = -1;
        while (i < n) {
            if (!isdigit(s[i])) {
                ++i;
                continue;
            }
            int start = i;
            while (i < n && isdigit(s[i])) {
                ++i;
            }
            int num = stoi(s.substr(start, i-start));
            if (last >= num) {
                return false;
            }
            last = num;
        }
        return true;
    }
};
