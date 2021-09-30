static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

// Forward declaration of ArrayReader class.
class ArrayReader;

class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        int l = 0, r = 9999;
        while (l < r) {
            int mid = l+(r-l)/2;
            int val = reader.get(mid);
            if (2147483647 == val) {
                r = mid-1;
            } else if (val == target) {
                return mid;    
            } else if (val > target) {
                r = mid-1;
            } else {
                l = mid+1;
            }
        }
        return reader.get(l)==target?l:(-1);
    }
};
