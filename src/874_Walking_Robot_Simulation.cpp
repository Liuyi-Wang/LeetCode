static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        set<pair<int, int>> s;
        for (const auto& o:obstacles) {
            s.insert(pair<int, int>(o[0], o[1]));
        }
        int x = 0, y = 0;
        d_x = {0, 1, 0, -1};
        d_y = {1, 0, -1, 0};
        int face = 0;   /// 0, n, 1, e, 2, s, 3, w
        int result = 0;
        for (auto c:commands) {
            if (-2 == c) {
                face = (face+3)%4;
                continue;
            } else if (-1 == c) {
                face = (face+1)%4;
                continue;
            }
            for (int i = 0; i < c; ++i) {
                int X = x+d_x[face];
                int Y = y+d_y[face];
                if (s.find(pair<int, int>(X, Y)) != s.end()) {
                    break;
                }
                x = X;
                y = Y;
                result = max(result, x*x+y*y);
            }
        }
        return result;
    }
private:
    vector<int> d_x;
    vector<int> d_y;
};
