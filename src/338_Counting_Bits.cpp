static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> result(num+1, 0);
        if (0 == num) {
            return result;
        }
        result[1] = 1;
        for (int i = 2; i <= num; ++i) {
            if (0 == i%2) {
                result[i] = result[i/2];
            } else {
                result[i] = result[i/2]+1;
            }
        }
        return result;
    }
};
