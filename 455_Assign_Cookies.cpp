static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int index = 0;
        for (int i = 0; i < g.size(); ++i) {
            if (index == s.size()) {
                return i;
            }
            if (s[index] >= g[i]) {
                ++index;
                continue;
            }
            while (index < s.size() && s[index] < g[i]) {
                ++index;
            }
            if (index == s.size()) {
                return i;
            }
            ++index;
        }
        return g.size();
    }
};
