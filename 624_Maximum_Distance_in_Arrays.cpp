static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int l = arrays[0][0], r = arrays[0].back();
        int result = INT_MIN;
        for (int i = 1; i < arrays.size(); ++i) {
            result = max(result, abs(r-arrays[i][0]));
            result = max(result, abs(l-arrays[i].back()));
            l = min(l, arrays[i][0]);
            r = max(r, arrays[i].back());
        }
        return result;
    }
};
