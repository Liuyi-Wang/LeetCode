/**
 *  Time:
 *  O(nn)
 *  Space:
 *  O(n)
 */
class Solution {
    int K;
public:
    int minimumCost(string sentence, int k) {
        K = k;
        vector<int> lengths = parse(sentence);
        int n = lengths.size();
        if (n == 1) {
            return 0;
        }
        vector<int> dp(n, INT_MAX/2);
        dp[0] = cost(lengths[0]);
        for (int i = 1; i < n-1; ++i) {
            int l = lengths[i];
            dp[i] = dp[i-1]+cost(l);
            for (int j = i-1; j >= 0; --j) {
                l += lengths[j]+1;
                if (l > k) {
                    break;
                }
                if (j == 0) {
                    dp[i] = min(dp[i], cost(l));
                } else {
                    dp[i] = min(dp[i], dp[j-1]+cost(l));
                }
            }
        }
        int l = lengths.back();
        dp.back() = dp[n-2];
        for (int j = n-2; j >= 0; --j) {
            l += lengths[j]+1;
            if (l > k) {
                break;
            }
            if (j == 0) {
                dp.back() = 0;
            } else {
                dp.back() = min(dp.back(), dp[j-1]);
            }
        }
        return dp.back();
    }
    
    vector<int> parse(const string& sentence) {
        int i = 0;
        int n = sentence.size();
        vector<int> v;
        while (i < n) {
            int begin = i;
            while (i < n && sentence[i] != ' ') {
                ++i;
            }
            v.push_back(i-1-begin+1);
            ++i;
        }
        return v;
    }
    
    int cost(int n) {
        return (K-n)*(K-n);
    }
};
