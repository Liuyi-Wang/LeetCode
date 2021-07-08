class Solution {
public:
    void reverseWords(vector<char>& s) {
        reverse(s.begin(), s.end());
		int i = 0;
        int l = i;
        while (i < s.size()) {
            if (s[i] != ' ') {
                ++i;
                continue;
            }
            reverse(s.begin()+l, s.begin()+i);
            ++i;
            l = i;
        }
        reverse(s.begin()+l, s.begin()+i);
    }
};
