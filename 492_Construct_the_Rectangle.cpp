static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<int> constructRectangle(int area) {
        int L = sqrt(area);
        while (0 != area%L) {
            --L;
        }
        vector<int> result;
        result.push_back(max(L, area/L));
        result.push_back(min(L, area/L));
        return result;
    }
};
