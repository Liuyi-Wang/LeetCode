static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int numSpecialEquivGroups(vector<string>& A) {
        unordered_set<string> s;
        for (const auto& a:A) {
            string o, e;
            for (int i = 0; i < a.size(); ++i) {
                if (1 == i%2) {
                    o += a[i];
                } else {
                    e += a[i];
                }
            }
            sort(o.begin(), o.end());
            sort(e.begin(), e.end());
            o += e;
            s.insert(o);
        }
        return s.size();
    }
};
