class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        string N = to_string(n);
        int l = N.size();
        int d = digits.size();
        int result = 0;
        for (int i = 1; i <= l-1; ++i) {
            result += pow(d, i);
        }
        return result+dfs(digits, N, 0);
    }
    
    int dfs(const vector<string>& digits, const string& N, int i) {
        if (i == N.size()) {
            return 1;
        }
        int result = 0;
        int l = N.size()-1-i-1+1;
        for (int j = 0; j < digits.size(); ++j) {
            if (digits[j][0] < N[i]) {
                result += pow(digits.size(), l);
            } else if (digits[j][0] == N[i]) {
                result += dfs(digits, N, i+1);
            } else {
                break;
            }
        }
        return result;
    }
};
