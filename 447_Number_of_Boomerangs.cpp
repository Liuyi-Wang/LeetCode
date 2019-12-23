static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int result = 0;
        for (int i = 0; i < points.size(); ++i) {
            unordered_map<int, int> counts;
            for (int j = 0; j < points.size(); ++j) {
                int a = points[i][0]-points[j][0];
                int b = points[i][1]-points[j][1];
                ++counts[a*a+b*b];
            }
            for (auto c:counts) {
                result += c.second*(c.second-1);
            }
        }
        return result;
    }
};
