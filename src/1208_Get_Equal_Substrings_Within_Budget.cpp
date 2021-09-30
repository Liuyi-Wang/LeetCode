static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int result = 0;
        int l = 0, r = 0;
        int cost = 0;
        while (r < s.size()) {
            cost += abs(s[r]-t[r]);
            while (l <= r && cost > maxCost) {
                cost -= abs(s[l]-t[l]);
                ++l;
            }
            result = max(result, r-l+1);
            ++r;
        }
        return result;
    }
};
