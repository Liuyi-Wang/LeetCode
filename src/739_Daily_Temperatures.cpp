static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> result(T.size(), 0);
        stack<pair<int, int>> s;
        s.push({T.back(), T.size()-1});
        for (int i = T.size()-2; i >= 0; --i) {
            while (!s.empty() && s.top().first <= T[i]) {
                s.pop();
            }
            if (!s.empty()) {
                result[i] = s.top().second-i;
            }
            s.push({T[i], i});
        }
        return result;
    }
};
