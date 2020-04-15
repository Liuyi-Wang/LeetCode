static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    struct less_than {
        inline bool operator() (const vector<int> &p1,
                                const vector<int> &p2) {
            return p1[1] < p2[1];
        }    
    };
    
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), less_than());
        int result = 0;
        int end = INT_MIN;
        for (const auto &p:pairs) {
            if (p[0] > end) {
                ++result;
                end = p[1];
            }
        }
        return result;
    }
};
