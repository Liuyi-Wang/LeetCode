/**
 *  Time:
 *  O(nlogn)
 *  Space:
 *  O(1)
 */
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        auto cmp = [](const vector<int>& v1, const vector<int>& v2) {
            if (v1[1] == v2[1]) {
                return v1[0] < v2[0];
            }
            return v1[1] < v2[1];
        };
        sort(points.begin(), points.end(), cmp);
        int i = 0;
        int n = points.size();
        int result = 0;
        while (i < n) {
            ++result;
            int j = i+1;
            while (j < n && points[j][0] <= points[i][1]) {
                ++j;
            }
            i = j;
        }
        return result;
    }
};
