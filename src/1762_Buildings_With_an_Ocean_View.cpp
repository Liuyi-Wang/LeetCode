class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        int n = heights.size();
        vector<int> result = {n-1};
        int high = heights.back();
        for (int i = n-2; i >= 0; --i) {
            if (heights[i] > high) {
                result.push_back(i);
                high = heights[i];
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
