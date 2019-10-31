static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int f(int a) {
        int r = a;
        while (r != d_r[r]) {
            r = d_r[r];
        }
        while (r != d_r[a]) {
            int t = d_r[a];
            d_r[a] = r;
            a = t;
        }
        return r;
    }
    
    void u(int a, int b) {
        int ra = f(a);
        int rb = f(b);
        if (ra != rb) {
            d_r[ra] = rb;
        }
    }
    
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size();
        d_r = vector<int>(n, 0);
        for (int i = 1; i < n; ++i) {
            d_r[i] = i;
        }
        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j < n; ++j) {
                if (1 == M[i][j]) {
                    u(i, j);
                }
            }
        }
        int result = 0;
        for (int i = 0; i < n; ++i) {
            if (i == f(i)) {
                ++result;
            }
        }
        return result;
    }
    
private:
    vector<int> d_r;
};
