static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int checkRecord(int n) {
        if (1 == n) {
            return 3;
        }
        const int M = 1e9+7;
        vector<long> p(n, 0);
        p[0] = 1;
        vector<long> pl(n, 0);
        pl[0] = 2;
        p[1] = 2;
        pl[1] = 4;
        for (int i = 2; i < n; ++i) {
            p[i] = pl[i-1];
            pl[i] = (p[i]+p[i-1]+p[i-2])%M;
        }
        long result = pl.back();
        result += 2*pl[n-2]%M;
        for (int i = 1; i < n-1; ++i) {
            long t = (pl[i-1]*pl[n-i-1-1])%M;
            result = (result+t)%M;
        }
        return result;
    }
};
