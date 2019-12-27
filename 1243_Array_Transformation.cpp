static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<int> transformArray(vector<int>& arr) {
        vector<vector<int>> v(2, arr);
        int i = 0;
        while (true) {
            bool change = false;
            for (int j = 1; j < arr.size()-1; ++j) {
                if (v[i][j] < v[i][j-1] && v[i][j] < v[i][j+1]) {
                    v[(i+1)%2][j] = v[i][j]+1;
                    change = true;
                } else if (v[i][j] > v[i][j-1] && v[i][j] > v[i][j+1]) {
                    v[(i+1)%2][j] = v[i][j]-1;
                    change = true;
                } else {
                    v[(i+1)%2][j] = v[i][j];
                }
            }
            if (!change) {
                break;
            }
            i = (i+1)%2;
        }
        return v[i];
    }
};
