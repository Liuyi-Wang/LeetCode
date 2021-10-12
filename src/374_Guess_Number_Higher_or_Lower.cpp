/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int l = 0, r = n;
        while (l < r) {
            int mid = l+(r-l)/2;
            int rc = guess(mid);
            if (rc == 0) {
                return mid;
            }
            if (rc == -1) {
                r = mid-1;
            } else {
                l = mid+1;
            }
        }
        return l;
    }
};
