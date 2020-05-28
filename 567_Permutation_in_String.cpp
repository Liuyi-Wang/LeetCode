static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) {
            return false;
        }
        vector<int> counts1(26, 0);
        int n = 0;
        for (auto c:s1) {
            ++counts1[c-'a'];
            if (1 == counts1[c-'a']) {
                ++n;
            }
        }
        vector<int> counts2(26, 0);
        int m = 0;
        for (int i = 0; i < s1.size(); ++i) {
            ++counts2[s2[i]-'a'];
            if (counts1[s2[i]-'a'] == counts2[s2[i]-'a']) {
                ++m;
            } else if (counts1[s2[i]-'a'] == counts2[s2[i]-'a']-1) {
                --m;
            }
        }
        if (m == n) {
            return true;
        }
        for (int i = s1.size(); i < s2.size(); ++i) {
            ++counts2[s2[i]-'a'];
            if (counts1[s2[i]-'a'] == counts2[s2[i]-'a']) {
                ++m;
            } else if (counts1[s2[i]-'a'] == counts2[s2[i]-'a']-1) {
                --m;
            }
            --counts2[s2[i-s1.size()]-'a'];
            if (counts1[s2[i-s1.size()]-'a'] == counts2[s2[i-s1.size()]-'a']) {
                ++m;
            } else if (counts1[s2[i-s1.size()]-'a'] == counts2[s2[i-s1.size()]-'a']+1) {
                --m;
            }
            if (m == n) {
                return true;
            }
        }
        return false;
    }
};
