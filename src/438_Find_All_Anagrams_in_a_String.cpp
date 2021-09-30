static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int count = 0;
        vector<int> v(26, 0);
        for (auto c:p) {
            if (0 == v[c-'a']) {
                ++count;
            }
            ++v[c-'a'];
        }
        vector<int> result;
        int l = 0, r = 0;
        int match = 0;
        vector<int> counts(26, 0);
        while (r < s.size()) {
            char c = s[r];
            ++counts[c-'a'];
            if (v[c-'a'] == counts[c-'a']) {
                ++match;
                if (match == count) {
                    result.push_back(l);
                }
            } else if (v[c-'a'] < counts[c-'a']) {
                --match;
                while (v[c-'a'] < counts[c-'a']) {
                    if (counts[s[l]-'a'] == v[s[l]-'a']) {
                        --match;
                    }
                    --counts[s[l]-'a'];
                    if (counts[s[l]-'a'] == v[s[l]-'a']) {
                        ++match;
                    }
                    ++l;
                    if (match == count) {
                        result.push_back(l);
                    }
                }    
            }
            ++r;
        }
        return result;
    }
};
