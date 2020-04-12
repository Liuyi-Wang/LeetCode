static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
        int m = days.size();
        int n = days[0].size();
        for (int i = 1; i < m; ++i) {
            if (0 == flights[0][i]) {
                days[i][0] = -1;
            }
        }
        for (int j = 1; j < n; ++j) {
            for (int i = 0; i < m; ++i) {
                int d = 0;
                bool find = false;
                for (int k = 0; k < m; ++k) {
                    if (0 == flights[k][i]) {
                        continue;
                    }
                    if (-1 == days[k][j-1]) {
                        continue;
                    }
                    d = max(d, days[k][j-1]+days[i][j]);
                    find = true;
                }
                if (find) {
                    if (-1 == days[i][j-1]) {
                        days[i][j] = d;
                    } else {
                        days[i][j] = max(d, days[i][j-1]+days[i][j]);
                    }
                } else {
                    if (-1 == days[i][j-1]) {
                        days[i][j] = -1;
                    } else {
                        days[i][j] = days[i][j-1]+days[i][j];
                    }
                }
            }
        }
        int result = INT_MIN;
        for (int i = 0; i < m; ++i) {
            result = max(result, days[i].back());
        }
        return result;
    }
};
