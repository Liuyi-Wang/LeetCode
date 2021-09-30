class Solution {
public:
    long long solve(vector<int>& v, int l) {
        sort(v.begin(), v.end());
        long long start = 0;
        long long result = 0;
        for (int i = 0; i < v.size(); ++i) {
            result = max(result, static_cast<long long>(v[i]-start));
            start = v[i];
        }
        return max(result, l-start);
    } 
    
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        long long hh = solve(horizontalCuts, h)%(1000000007);
        long long ww = solve(verticalCuts, w)%(1000000007);
        long long result = hh*ww%1000000007;
        return result;
    }
};
