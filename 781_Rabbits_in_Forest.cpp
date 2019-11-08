static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> counts;
        for (auto a:answers) {
            ++counts[a+1];
        }
        int result = 0;
        for (unordered_map<int, int>::iterator it = counts.begin(); it != counts.end(); ++it) {
            result += it->first*((it->second-1)/it->first+1);
        }
        return result;
    }
};
