static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    bool isReflected(vector<vector<int>>& points) {
        int xmin = INT_MAX, xmax = INT_MIN;
        unordered_map<int, set<int>> hash;
        for (int i = 0; i < points.size(); ++i) {
            xmin = min(xmin, points[i][0]);
            xmax = max(xmax, points[i][0]);
            hash[points[i][0]].insert(points[i][1]);
        }
        double mid = double(xmin+xmax)/2;
        for (int i = 0; i < points.size(); ++i) {
            int x = 2*mid-points[i][0];
            if (hash.find(x) == hash.end() || hash[x].find(points[i][1]) == hash[x].end()) {
                return false;
            }
        }
        return true;
    }
};
