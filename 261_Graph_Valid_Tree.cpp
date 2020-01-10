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
        while (r != d_roots[r]) {
            r = d_roots[r];
        }
        while (r != d_roots[a]) {
            int t = d_roots[a];
            d_roots[a] = r;
            a = t;
        }
        return r;
    }
    
    bool u(int a, int b) {
        int ra = f(a);
        int rb = f(b);
        if (ra == rb) {
            return false;
        }
        d_roots[ra] = rb;
        --d_n;
        return true;
    }
    
    bool validTree(int n, vector<vector<int>>& edges) {
        for (int i = 0; i < n; ++i) {
            d_roots.push_back(i);
        }
        d_n = n;
        for (const auto &e:edges) {
            if (!u(e[0], e[1])) {
                return false;
            }
        }
        return 1==d_n;
    }

private:
    vector<int> d_roots;
    int d_n;
};
