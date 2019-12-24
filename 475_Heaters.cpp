static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(), heaters.end());
        int result = INT_MIN;
        for (auto h:houses) {
            int l = 0;
            int r = heaters.size()-1;
            while (l+1 < r) {
                int m = l+(r-l)/2;
                if (heaters[m] == h) {
                    r = m;
                    break;
                } else if (heaters[m] < h) {
                    l = m;
                } else {
                    r = m-1;
                }
            }
            int lh = l;
            if (heaters[r] <= h) {
                lh = r;
            }
            l = 0;
            r = heaters.size()-1;
            while (l+1 < r) {
                int m = l+(r-l)/2;
                if (heaters[m] == h) {
                    l = m;
                    break;
                } else if (heaters[m] < h) {
                    l = m+1;
                } else {
                    r = m;
                }
            }
            int rh = r;
            if (heaters[l] >= h) {
                rh = l;
            }
            //cout << h << ";" << heaters[lh] << ";" << heaters[rh] << endl;
            result = max(result, min(abs(heaters[lh]-h), abs(heaters[rh]-h)));
        }
        return result;
    }
};
