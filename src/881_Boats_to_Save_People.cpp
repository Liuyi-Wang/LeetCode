static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int begin = 0, end = people.size()-1;
        int result = 0;
        while (begin < end) {
            if (people[begin]+people[end] <= limit) {
                ++begin;
            }
            ++result;
            --end;
        }
        if (begin == end) {
            ++result;
        }
        return result;
    }
};
