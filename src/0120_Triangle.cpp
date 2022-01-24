/**
 *  Time:
 *  O(n)
 *  Space:
 *  O(1)
 */
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for (int i = 1; i < triangle.size(); ++i) {
            triangle[i][0] += triangle[i-1][0];
            triangle[i].back() += triangle[i-1].back();
            for (int j = 1; j < triangle[i].size()-1; ++j) {
                triangle[i][j] += min(triangle[i-1][j-1], triangle[i-1][j]);
            }
        }
        int result = INT_MAX;
        for (int i = 0; i < triangle.back().size(); ++i) {
            result = min(result, triangle.back()[i]);
        }
        return result;
    }
};
