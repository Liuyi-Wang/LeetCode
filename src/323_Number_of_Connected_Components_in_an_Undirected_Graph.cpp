static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int fd(int i) {
        int r = i;
        while (r != d_roots[r]) {
            r = d_roots[r];
        }
        while (d_roots[i] != r) {
            int t = d_roots[i];
            d_roots[i] = r;
            i = t;
        }
        return r;
    }
    
    void un(int a, int b) {
        int ra = fd(a);
        int rb = fd(b);
        if (ra != rb) {
            --d_count;
            d_roots[ra] = rb;
        }
    }
    
    int countComponents(int n, vector<vector<int>>& edges) {
        for (int i = 0; i < n; ++i) {
            d_roots.push_back(i);
        }
        d_count = n;
        for (const auto &edge:edges) {
            un(edge[0], edge[1]);
        }
        return d_count;
    }
    
private:
    vector<int> d_roots;
    int d_count;
};
