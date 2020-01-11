static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        for (int i = 0; i < citations.size(); ++i) {
           if (citations.size()-i <= citations[i]) {
               return citations.size()-i;
           }
        }
        return 0;
    }
};
