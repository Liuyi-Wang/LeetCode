class Solution {
public:
    int gcd(int a, int b) {
        return a==0?b:gcd(b%a, a);
    }
    
    void solve(vector<string> &result, int i, int n) {
        for (int j = i+1; j <= n; ++j) {
            if (1 != gcd(i, j)) {
                continue;
            }
            result.push_back(to_string(i)+"/"+to_string(j));
        }
    }
    
    vector<string> simplifiedFractions(int n) {
        vector<string> result;
        for (int i = 1; i < n; ++i) {
            solve(result, i, n);
        }
        return result;
    }
};
