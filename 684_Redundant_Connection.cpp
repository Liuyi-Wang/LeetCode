static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int f(int a) {
        int r = d_r[a];
        while (r != d_r[r]) {
            r = d_r[r];
        }
        while (d_r[a] != r) {
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
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        for (int i = 0; i <= n; ++i) {
            d_r.push_back(i);
        }
        for (const auto &p:edges) {
            if (f(p[0]) == f(p[1])) {
                return p;
            }
            u(p[0], p[1]);
        }
        vector<int> result;
        return result;
    }
    
private:
    vector<int> d_r;
};
