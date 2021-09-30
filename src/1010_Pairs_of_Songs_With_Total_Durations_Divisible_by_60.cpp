class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> v(60, 0);
        for (auto t:time) {
            ++v[t%60];
        }
        int result = v[0]*(v[0]-1)/2;
        for (int i = 1; i <= 29; ++i) {
            result += v[i]*v[60-i];
        }
        result += v[30]*(v[30]-1)/2;
        return result;
    }
};
