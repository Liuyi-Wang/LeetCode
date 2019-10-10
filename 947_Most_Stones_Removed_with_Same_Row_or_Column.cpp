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
            d_r[rb] = ra;
        }
    }
    
    int removeStones(vector<vector<int>>& stones) {
        d_r = vector<int>(stones.size(), 0);
        for (int i = 1; i < stones.size(); ++i) {
            d_r[i] = i;
        }
        for (int i = 0; i < stones.size(); ++i) {
            for (int j = i+1; j < stones.size(); ++j) {
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    u(i, j);
                }
            }
        }
        vector<int> v(d_r.size(), 0);
        for (int i = 0; i < d_r.size(); ++i) {
            ++v[f(i)];
        }
        int result = 0;
        for (int i = 0; i < v.size(); ++i) {
            if (0 != v[i]) {
                result += v[i]-1;
            }
        }
        return result;
    }
    
private:
    vector<int> d_r;
};
