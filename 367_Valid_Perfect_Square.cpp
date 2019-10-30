static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int mySqrt(int x) {
        if (x <= 1) {
            return x;
        }
        int left = 1, right = x;
        while (left+1 < right) {
            int mid = left+(right-left)/2;
            if (mid <= x/mid) {
                left = mid;
            } else {
                right = mid-1;
            }
        }
        if (right <= x/right) {
            return right;
        }
        return left;
    }
    
    bool isPerfectSquare(int num) {
        int square = mySqrt(num);
        return square*square==num;
    }
};
