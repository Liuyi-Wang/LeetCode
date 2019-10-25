static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        if (position.size() < 2) {
            return position.size();
        }
        unordered_map<int, int> pc;
        for (int i = 0; i < position.size(); ++i) {
            pc[position[i]] = i;
        }
        sort(position.begin(), position.end());
        int ih = position.size()-1;
        int ic = ih-1;
        int result = 1;
        while (ic >= 0) {
            int h = pc[position[ih]];
            int c = pc[position[ic]];
            if (speed[c] <= speed[h]) {
                ih = ic;
                ++result;
            } else {
                double dp = position[ih]-position[ic];
                double ds = speed[c]-speed[h];
                double t = dp/ds;
                if (position[ih]+speed[h]*t > target) {
                    ih = ic;
                    ++result;
                }
            }
            --ic;
        }
        return result;
    }
};
