static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int maxProduct(vector<string>& words) {
        if (0 == words.size()) {
            return 0;
        }
        map<int, int> hash;
        for (const auto &w:words) {
            int mask = 0;
            for (auto c:w) {
                mask |= (1<<(c-'a'));
            }
            hash[mask] = max(hash[mask], int(w.size()));
        }
        int result = 0;
        for (map<int, int>::iterator it = hash.begin(); it != hash.end(); ++it) {
            map<int, int>::iterator itt = it;
            ++itt;
            for (; itt != hash.end(); ++itt) {
                if ((it->first & itt->first) != 0) {
                    continue;
                }
                result = max(result, it->second*itt->second);
            }
        }
        return result;
    }
};
