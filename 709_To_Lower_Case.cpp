static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    string toLowerCase(string str) {
        for (int i = 0; i < str.size(); ++i) {
            if (str[i] <= 90 && str[i] >= 65) {
                str[i] += 32;
            }
        }
        return str;
    }
};
