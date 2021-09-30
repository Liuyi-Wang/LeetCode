static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int minSwaps(vector<int>& data) {
        int n = 0;
        for (auto d:data) {
            if (1 == d) {
                ++n;
            }
        }
        if (1 == n) {
            return 0;
        }
        if (data.size() == n) {
            return 0;
        }
        int m = 0;
        int i = 0;
        for (; i < n; ++i) {
            if (1 == data[i]) {
                ++m;
            }
        }
        int result = n-m;
        for (; i < data.size(); ++i) {
            if (data[i] == 1) {
                ++m;
            }
            if (data[i-n] == 1) {
                --m;
            }
            result = min(result, n-m);
        }
        return result;
    }
};
