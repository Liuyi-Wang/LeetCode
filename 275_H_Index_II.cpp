static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int hIndex(vector<int>& citations) {
        if (0 == citations.size()) {
            return 0;
        }
        int l = 0, r = citations.size()-1;
        while (l+1 < r) {
            int m = l+(r-l)/2;
            if (citations.size()-m<=citations[m]) {
                r = m;
            } else {
                l = m+1;
            }
        }
        if (citations.size()-l<=citations[l]) {
            return citations.size()-l;
        } else if (citations.size()-r<=citations[r]) {
            return citations.size()-r;
        }
        return 0;
    }
};
