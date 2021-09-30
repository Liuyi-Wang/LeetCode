class Solution {
public:
    int maxArea(vector<int>& height) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int begin = 0, end = height.size()-1;
        int result = 0;
        while (begin < end) {
            if (height[begin] < height[end]) {
                result = max(result, height[begin]*(end-begin));
                ++begin;
            } else {
                result = max(result, height[end]*(end-begin));
                --end;
            }
        }
        return result;
    }
};
