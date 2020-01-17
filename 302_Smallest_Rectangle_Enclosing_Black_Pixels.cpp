static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    bool row(const vector<vector<char>> &image, int x) {
        for (int i = 0; i < image[0].size(); ++i) {
            if ('1' == image[x][i]) {
                return true;
            }
        }
        return false;
    }
    
    bool col(const vector<vector<char>> &image, int y) {
        for (int i = 0; i < image.size(); ++i) {
            if ('1' == image[i][y]) {
                return true;
            }
        }
        return false;
    }
    
    int up(const vector<vector<char>> &image, int x, int y) {
        int u = 0, d = x;
        while (u+1 < d) {
            int m = u+(d-u)/2;
            if (row(image, m)) {
                d = m;
            } else {
                u = m+1;
            }
        }
        if (row(image, u)) {
            return u;
        }
        return d;
    }
    
    int down(const vector<vector<char>> &image, int x, int y) {
        int u = x, d = image.size()-1;
        while (u+1 < d) {
            int m = u+(d-u)/2;
            if (row(image, m)) {
                u = m;
            } else {
                d = m-1;
            }
        }
        if (row(image, d)) {
            return d;
        }
        return u;
    }
    
    int left(const vector<vector<char>> &image, int x, int y) {
        int l = 0, r = y;
        while (l+1 < r) {
            int m = l+(r-l)/2;
            if (col(image, m)) {
                r = m;
            } else {
                l = m+1;
            }
        }
        if (col(image, l)) {
            return l;
        }
        return r;
    }
    
    int right(const vector<vector<char>> &image, int x, int y) {
        int l = y, r = image[0].size()-1;
        while (l+1 < r) {
            int m = l+(r-l)/2;
            if (col(image, m)) {
                l = m;
            } else {
                r = m-1;
            }
        }
        if (col(image, r)) {
            return r;
        }
        return l;
    }
    
    int minArea(vector<vector<char>>& image, int x, int y) {
        int u = up(image, x, y);
        int d = down(image, x, y);
        int l = left(image, x, y);
        int r = right(image, x, y);
        return (d-u+1)*(r-l+1);
    }
};
