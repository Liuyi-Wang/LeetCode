static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        set<int> s;
        int xi = 1;
        for (int i = 0; i < INT_MAX; ++i) {
            if (xi >= bound) {
                break;
            }
            int yj = 1;
            for (int j = 0; j < INT_MAX; ++j) {
                int sum = xi+yj; 
                if (sum <= bound) {
                    s.insert(sum);
                }
                if (sum >= bound) {
                    break;
                }
                if (1 == y) {
                    break;
                }
                yj *= y;
            }
            if (1 == x) {
                break;
            }
            xi *= x;
        }
        vector<int> result(s.begin(), s.end());
        return result;
    }
};
