static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int i = 0;
        for (; i < bits.size()-1;) {
            i += bits[i]==1?2:1;
        }
        return i==(bits.size()-1);
    }
};
