static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if (0 == s.size() || 0 == k) {
            return 0;
        }
        vector<int> hash(256, 0);
        int result = 1;
        int j = 0;
        hash[s[0]] = 1;
        int count = 1;
        for (int i = 1; i < s.size(); ++i) {
            ++hash[s[i]];
            if (1 == hash[s[i]]) {
                ++count;
            }
            if (count <= k) {
                result = max(result, i-j+1);
            } else {
                for (; j <= i;) {
                    --hash[s[j]];
                    if (0 == hash[s[j]]) {
                        --count;
                    }
                    ++j;
                    if (count <= k) {
                        result = max(result, i-j+1);
                        break;
                    }
                }
            }
        }
        return result;
    }
};
