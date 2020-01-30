static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        if (1 == n) {
            return 1;
        }
        vector<int> num(1, 1);
        --n;
        vector<int> is(primes.size(), 0);
        while (n > 0) {
            int next = primes[0]*num[is[0]];
            int nexti = 0;
            vector<int> nextis;
            nextis.push_back(nexti);
            for (int i = 1; i < primes.size(); ++i) {
                int m = primes[i]*num[is[i]];
                if (next > m) {
                    next = m;
                    nexti = i;
                    nextis.clear();
                    nextis.push_back(i);
                } else if (next == m) {
                    nextis.push_back(i);
                }
            }
            num.push_back(next);
            for (auto i:nextis) {
                ++is[i];
            }
            --n;
        }
        return num.back();
    }
};
