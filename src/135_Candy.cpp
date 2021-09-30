static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> candies(ratings.size(), 1);
        for (int i = 1; i < ratings.size(); ++i) {
            if (ratings[i] > ratings[i-1]) {
                candies[i] = candies[i-1]+1;
            }
        }
        int result = candies.back();
        for (int i = candies.size()-2; i >= 0; --i) {
            if (ratings[i] > ratings[i+1]) {
                candies[i] = max(candies[i], candies[i+1]+1);
            }
            result += candies[i];
        }
        return result;
    }
};
