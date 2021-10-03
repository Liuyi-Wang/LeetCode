class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        vector<int> result;
        int h = 0;
        for (int i = static_cast<int>(heights.size())-1; i >= 0; --i) {
            if (heights[i] > h) {
                result.push_back(i);
                h = heights[i];
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
