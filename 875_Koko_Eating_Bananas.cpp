static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    bool valid(const vector<int>& piles, int K, int H) {
        int h = 0;
        for (auto p:piles) {
            h += p/K;
            h = (p%K)==0?h:(h+1);
            if (h > H) {
                return false;
            }
        }
        return true;
    }
    
    int minEatingSpeed(vector<int>& piles, int H) {
        
        long long begin = 0, end = 0, sum = 0;
        for (const auto& p:piles) {
            sum += p;
            end = max(end, static_cast<long long>(p));
        }
        begin = sum/H;
        begin = (sum%H)==0?begin:(begin+1);
        while (begin+1 < end) {
            int mid = begin + (end-begin)/2;
            if (valid(piles, mid, H)) {
                end = mid;
            } else {
                begin = mid+1;
            }
        }
        if (valid(piles, begin, H)) {
            return begin;
        }
        return end;
    }
};
