static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    set<int> islands(int i, int j) {
        set<int> s;
        for (int k = 0; k < 4; ++k) {
            int I = i+d_i[k];
            int J = j+d_j[k];
            if (I >= 0 && J >= 0 && I < d_m && J < d_n && -1 != find(I, J)) {
                s.insert(find(I, J));
            }
        }
        return s;
    }
    
    int find(int i, int j) {
        if (-1 == d_roots[i][j]) {
            return -1;
        }
        int ri = i, rj = j;
        while (d_roots[ri][rj] != d_n*ri+rj) {
            int r = d_roots[ri][rj];
            ri = r/d_n;
            rj = r%d_n;
        }
        while (d_roots[i][j] != d_n*ri+rj) {
            int r = d_roots[i][j];
            d_roots[i][j] = d_n*ri+rj;
            i = r/d_n;
            j = r%d_n;
        }
        return d_n*ri+rj;
    }
    
    void u(int i, int j) {
        for (int k = 0; k < 4; ++k) {
            int I = i+d_i[k];
            int J = j+d_j[k];
            if (I >= 0 && J >= 0 && I < d_m && J < d_n && -1 != find(I, J)) {
                int r = find(I, J);
                d_roots[r/d_n][r%d_n] = d_n*i+j;
            }
        }
    }
    
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        vector<int> result;
        d_m = m;
        d_n = n;
        d_roots = vector<vector<int>>(d_m, vector<int>(d_n, -1));
        d_i = {-1, 0, 1, 0};
        d_j = {0, 1, 0, -1};
        for (const auto &p:positions) {
            if (-1 != d_roots[p[0]][p[1]]) {
                result.push_back(result.back());
                continue;
            }
            set<int> s = islands(p[0], p[1]);
            d_roots[p[0]][p[1]] = d_n*p[0]+p[1];
            result.push_back((result.empty()?0:result.back()) - (static_cast<int>(s.size())-1));
            u(p[0], p[1]);
        }
        return result;
    }
    
private:
    vector<vector<int>> d_roots;
    vector<int> d_i;
    vector<int> d_j;
    int d_m;
    int d_n; 
};
