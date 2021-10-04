class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int sum = 0;
        for (auto p:cardPoints) {
            sum += p;
        }
        int s = 0;
        for (int i = 0; i < n-k; ++i) {
            s += cardPoints[i];
        }
        int result = sum-s;
        for (int i = n-k; i < n; ++i) {
            s -= cardPoints[i+k-n];
            s += cardPoints[i];
            result = max(result, sum-s);
        }
        return result;
    }
};
