class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> standard = heights;
        sort(standard.begin(), standard.end());
        int result = 0;
        for (int i = 0; i < heights.size(); ++i) {
            if (heights[i] != standard[i]) {
                ++result;
            }
        }
        return result;
    }
};
