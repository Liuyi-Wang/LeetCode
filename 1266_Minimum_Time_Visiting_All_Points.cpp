static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int result = 0;
        for (int i = 1; i < points.size(); ++i) {
            int dx = abs(points[i][0]-points[i-1][0]);
            int dy = abs(points[i][1]-points[i-1][1]);
            result += max(dx, dy);
        }
        return result;
    }
};
