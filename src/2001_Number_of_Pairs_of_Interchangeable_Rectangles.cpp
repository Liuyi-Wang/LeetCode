class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        unordered_map<double, long long> counts;
        for (auto rectangle:rectangles) {
            if (rectangle[1] == 0) {
                ++counts[INT_MAX];
            } else {
                //cout << (double)rectangle[0]/(double)rectangle[1] << endl;
                ++counts[(double)rectangle[0]/(double)rectangle[1]];
            }
        }
        long long result = 0;
        for (auto it:counts) {
            result += it.second*(it.second-1)/2;
        }
        return result;
    }
};
