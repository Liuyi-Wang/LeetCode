static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> count;
        for (auto t:text) {
            ++count[t];
        }
        int result = INT_MAX;
        result = min(result, count['b']);
        result = min(result, count['a']);
        result = min(result, count['l']/2);
        result = min(result, count['o']/2);
        result = min(result, count['n']);
        return result;
    }
};
