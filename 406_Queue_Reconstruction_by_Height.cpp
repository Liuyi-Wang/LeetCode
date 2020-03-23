static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [] (const vector<int> &v1, const vector<int> &v2) {
            return v1[0] > v2[0] || (v1[0] == v2[0] && v1[1] < v2[1]);
        });
        vector<vector<int>> result;
        for (const auto &p:people) {
            result.insert(result.begin()+p[1], p);
        }
        return result;
    }
};
