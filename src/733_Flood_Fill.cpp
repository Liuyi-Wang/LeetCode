static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int oldColor = image[sr][sc];
        stack<pair<int, int>> s;
        s.push({sr, sc});
        image[sr][sc] = newColor;
        vector<int> d_r = {-1, 0, 1, 0};
        vector<int> d_c = {0, 1, 0, -1};
        vector<vector<bool>> v(image.size(), vector<bool>(image[0].size(), false));
        v[sr][sc] = true;
        while (!s.empty()) {
            int r = s.top().first;
            int c = s.top().second;
            s.pop();
            for (int i = 0; i < d_r.size(); ++i) {
                int R = r + d_r[i];
                int C = c + d_c[i];
                if (R < 0 || C < 0 || R >= image.size() || C >= image[0].size()) {
                    continue;
                }
                if (!v[R][C] && oldColor == image[R][C]) {
                    v[R][C] = true;
                    image[R][C] = newColor;
                    s.push({R, C});
                }
            }
        }
        return image;
    }
};
