static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> count;
        for (auto c:s) {
            ++count[c];
        }
        sort(s.begin(), s.end(), [&](char &c1, char &c2) {
            return count[c1]>count[c2] || (count[c1]==count[c2] && c1 < c2);
        });
        return s;
    }
};
