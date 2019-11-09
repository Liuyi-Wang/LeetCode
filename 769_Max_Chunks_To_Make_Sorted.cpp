static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int result = 0;
        for (int i = 0; i < arr.size();) {
            int end = arr[i];
            while (i <= end) {
                if (arr[i] > end) {
                    end = arr[i];
                }
                ++i;
            }
            ++result;
        }
        return result;
    }
};
