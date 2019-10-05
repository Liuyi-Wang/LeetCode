static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    void solve(const vector<vector<vector<int>>>& f, int src, const int& dst, int k, const int& K, int price) {
        if (price >= d_result) {
            return;
        }
        if (dst == src) {
            d_find = true;
            d_result = min(d_result, price);
            return;
        }
        if (k > K) {
            return;
        }
        /*
        cout << src << "," << dst << "," << k << "," << K << "," << price << endl;
        cout << f[src].size() << "size" << endl;
        */
        for (int i = 0; i < f[src].size(); ++i) {
            solve(f, f[src][i][1], dst, k+1, K, price+f[src][i][2]);
        }
    }
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<vector<vector<int>>> f(n, vector<vector<int>>());
        for (const auto& flight:flights) {
            f[flight[0]].push_back(flight);
        }
        /*
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < f[i].size(); ++j) {
                cout << i << ":" << f[i][j][0] << "," << f[i][j][1] << "," << f[i][j][2] << endl;
            }
        }
        */
        d_result = INT_MAX;
        d_find = false;
        solve(f, src, dst, 0, K, 0);
        if (d_find) {
            return d_result;
        }
        return -1;
    }
private:
    int d_result;
    bool d_find;
};
