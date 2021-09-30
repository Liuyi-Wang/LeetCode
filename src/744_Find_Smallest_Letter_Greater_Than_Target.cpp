static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int l = 0, r = letters.size()-1;
        while (l+1 < r) {
            int m = l+(r-l)/2;
            if (letters[m] <= target) {
                l = m+1;
            } else {
                r = m;
            }
        }
        if (letters[l] > target) {
            return letters[l];
        }
        if (letters[r] > target) {
            return letters[r];
        }
        return letters[0];
    }
};
