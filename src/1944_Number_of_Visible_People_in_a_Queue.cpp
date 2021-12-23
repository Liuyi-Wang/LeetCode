/**
 *  Time:
 *  O(n)
 *  Space:
 *  O(n)
 */
class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        vector<int> result(n, 0);
        vector<int> stk;
        stk.push_back(heights.back());
        for (int i = n-2; i >= 0; --i) {
            int count = 0;
            while (stk.size() > 0 && stk.back() < heights[i]) {
                stk.pop_back();
                ++count;
            }
            if (stk.size() == 0) {
                result[i] = count;
                stk.push_back(heights[i]);
            } else {
                result[i] = count+1;
                if (stk.back() > heights[i]) {
                    stk.push_back(heights[i]);
                }
            }
        }
        return result;
    }
};
