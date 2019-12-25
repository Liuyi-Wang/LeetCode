static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if (0 == timeSeries.size()) {
            return 0;
        }
        int begin = 0;
        int end = timeSeries[begin]+duration-1;
        int result = 0;
        while (begin < timeSeries.size()) {
            int i = begin+1;
            while (i < timeSeries.size() && timeSeries[i] <= end) {
                end = timeSeries[i++]+duration-1;
            }
            result += end-timeSeries[begin]+1;
            begin = i;
            if (i < timeSeries.size()) {
                end = timeSeries[begin]+duration-1;
            }
        }
        return result;
    }
};
