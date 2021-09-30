static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int dietPlanPerformance(vector<int>& calories, int k, int lower, int upper) {
        int sum = 0;
        int result = 0;
        for (int i = 0; i < calories.size() && i < k; ++i) {
            sum += calories[i];
        }
        if (sum < lower) {
            --result;
        } else if (sum > upper) {
            ++result;
        }
        for (int i = k; i < calories.size(); ++i) {
            sum += calories[i];
            sum -= calories[i-k];
            if (sum < lower) {
                --result;
            } else if (sum > upper) {
                ++result;
            }
        }
        return result;
    }
};
