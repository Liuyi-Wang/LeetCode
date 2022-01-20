/**
 *  Time:
 *  O(nlogp)
 *  Space:
 *  O(1)
 */
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = piles[0];
        int n = piles.size();
        for (int i = 1; i < n; ++i) {
            r = max(r, piles[i]);
        }
        while (l < r) {
            int m = l+(r-l)/2;
            if (eatAll(piles, m, h)) {
                r = m;
            } else {
                l = m+1;
            }
        }
        return l;
    }
    
    bool eatAll(const vector<int>& piles, int p, int h) {
        int time = 0;
        for (auto pile:piles) {
            time += ceil((double)pile/p);
        }
        return time <= h;
    }
};
