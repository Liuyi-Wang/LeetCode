static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int gcd(int a, int b) {
        return (b == 0) ? a : gcd(b, a % b);
    }
    
    int maxPoints(vector<vector<int>>& points) {
        int result = 0;
        for (int i = 0; i < points.size(); ++i) {
            int dup = 1;
            map<pair<int, int>, int> counts;
            int count = 0;
            for (int j = i+1; j < points.size(); ++j) {
                if (points[i][0] == points[j][0] && points[i][1] == points[j][1]) {
                    ++dup;
                    continue;
                }
                int c = gcd(points[j][1]-points[i][1], points[j][0]-points[i][0]);
                ++counts[{(points[j][1]-points[i][1])/c, (points[j][0]-points[i][0])/c}];
                count = max(count, counts[{(points[j][1]-points[i][1])/c, (points[j][0]-points[i][0])/c}]);
            }
            result = max(result, dup+count);
        }
        return result;
    }
};
