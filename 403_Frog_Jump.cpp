static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    bool canCross(vector<int>& stones) {
        vector<unordered_set<int>> jumps(stones.size(), unordered_set<int>());
        jumps[0].insert(0);
        vector<int> max_jump(stones.size(), 0);
        int last_stone = 0;
        for (int i = 1; i < stones.size(); ++i) {
            while (max_jump[last_stone]+1 < stones[i]-stones[last_stone]) {
                ++last_stone;
            }
            for (int j = last_stone; j < i; ++j) {
                int jump = stones[i]-stones[j];
                if (jumps[j].find(jump-1) != jumps[j].end() ||
                    jumps[j].find(jump) != jumps[j].end() ||
                    jumps[j].find(jump+1) != jumps[j].end()) {
                    jumps[i].insert(jump);
                    max_jump[i] = max(max_jump[i], jump);
                }
            }
        }
        return max_jump.back()>0;
    }
};
