static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int s = min(start, destination);
        int d = max(start, destination);
        int c1 = 0;
        for (int i = 0; i < s; ++i) {
            c1 += distance[i];
        }
        for (int i = d; i < distance.size(); ++i) {
            c1 += distance[i];
        }
        int c2 = 0;
        for (int i = s; i < d; ++i) {
            c2 += distance[i];
        }
        return min(c1, c2);
    }
};
