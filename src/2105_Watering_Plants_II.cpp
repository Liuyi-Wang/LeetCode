/**
 *  Time:
 *  O(n)
 *  Space:
 *  O(1)
 */
class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int n = plants.size();
        int result = 0;
        int a = capacityA;
        int b = capacityB;
        int l = 0, r = n-1;
        while (l < r) {
            if (a >= plants[l]) {
                a -= plants[l];
            } else {
                ++result;
                a = capacityA;
                a -= plants[l];
            }
            if (b >= plants[r]) {
                b -= plants[r];
            } else {
                ++result;
                b = capacityB;
                b -= plants[r];
            }
            ++l;
            --r;
        }
        if (n%2 == 0) {
            return result;
        }
        if (max(a, b) < plants[n/2]) {
            return result+1;
        }
        return result;
    }
};
