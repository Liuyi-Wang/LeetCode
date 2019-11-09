static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        int distance = abs(target[0])+abs(target[1]);
        for (const auto &g:ghosts) {
            if (distance >= abs(target[0]-g[0])+abs(target[1]-g[1])) {
                return false;
            }
        }
        return true;
    }
};
