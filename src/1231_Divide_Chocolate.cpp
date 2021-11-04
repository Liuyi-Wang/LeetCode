/**
 * Time Complexity:
 * Binary Search from 1 to sum/(k+1), log(sum/(k+1))
 * Valid check, iterate through sweetness, n.
 * O(n*log(sum/(k+1))
 * Space Complexity:
 * O(1)
 */
class Solution {
public:
    int maximizeSweetness(vector<int>& sweetness, int k) {
        unsigned long long sum = 0;
        for (auto s:sweetness) {
            sum += s;
        }
        int r = (sum/(k+1));
        int l = 1;
        while (l < r) {
            int mid = l+(r-l)/2+1;
            if (valid(sweetness, k, mid)) {
                l = mid;
            } else {
                r = mid-1;
            }
        }
        return l;
    }
    
    bool valid(const vector<int>& sweetness, int k, int mid) {
        int count = 0;
        int sum = 0;
        for (auto s:sweetness) {
            sum += s;
            if (sum >= mid) {
                ++count;
                sum = 0;
            }
            if (count >= k+1) {
                return true;
            }
        }
        return count >= k+1;
    }
};
