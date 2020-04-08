static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        unordered_map<int, int> sumCount;
        sumCount[0] = 1;
        for (auto n:nums) {
            unordered_map<int, int> sumC;
            for (unordered_map<int, int>::iterator it = sumCount.begin(); it != sumCount.end(); ++it) {
                sumC[it->first+n] += it->second;
                sumC[it->first-n] += it->second;
            }
            sumCount = sumC;
        }
        return sumCount[S];
    }
};
