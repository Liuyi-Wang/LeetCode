/**
 *  Time:
 *  O(n)
 *  Space:
 *  O(1)
 */
class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        pair<int, int> min1 = {INT_MAX, -1}, min2 = {INT_MAX, -1};
        pair<int, int> max1 = {INT_MIN, -1}, max2 = {INT_MIN, -1};
        for (int i = 0; i < arrays.size(); ++i) {
            if (arrays[i][0] < min1.first) {
                min2 = min1;
                min1 = {arrays[i][0], i};
            } else if (arrays[i][0] < min2.first) {
                min2 = {arrays[i][0], i};
            }
            if (arrays[i].back() > max1.first) {
                max2 = max1;
                max1 = {arrays[i].back(), i};
            } else if (arrays[i].back() > max2.first) {
                max2 = {arrays[i].back(), i};
            }
        }
        if (min1.second != max1.second) {
            return abs(min1.first-max1.first);
        }
        return max(abs(min1.first-max2.first), abs(min2.first-max1.first));
    }
};
