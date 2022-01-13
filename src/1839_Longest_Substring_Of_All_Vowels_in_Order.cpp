/**
 *  Time:
 *  O(n)
 *  Space:
 *  O(1)
 */
class Solution {
public:
    int longestBeautifulSubstring(string word) {
        return dp(word);
    }
    
    int slidingWindow(const string& word) {
        int result = 0;
        int i = 0;
        int n = word.size();
        unordered_map<char, int> hash;
        hash['a'] = 0;
        hash['e'] = 1;
        hash['i'] = 2;
        hash['o'] = 3;
        hash['u'] = 4;
        while (i < n) {
            while (i < n && word[i] != 'a') {
                ++i;
            }
            int begin = i;
            while (i < n) {
                if (word[i] == word[i-1]) {
                    ++i;
                } else if (hash[word[i]]-hash[word[i-1]] == 1) {
                    ++i;
                } else {
                    break;
                }
            }
            if (word[i-1] == 'u') {
                result = max(result, i-1-begin+1);
            }
        }
        return result;
    }
    
    int dp(const string& word) {
        int n = word.size();
        vector<int> dp(2, 0);
        int result = 0;
        if (word[0] == 'a') {
            dp[0] = 1;
        }
        result = 0;
        unordered_map<char, int> hash;
        hash['a'] = 0;
        hash['e'] = 1;
        hash['i'] = 2;
        hash['o'] = 3;
        hash['u'] = 4;
        for (int i = 1; i < n; ++i) {
            int cur = i%2;
            int pre = (cur+1)%2;
            if (dp[pre] == 0) {
                if (word[i] == 'a') {
                    dp[cur] = 1;
                } else {
                    dp[cur] = 0;
                }
                continue;
            }
            if (word[i] == word[i-1]) {
                dp[cur] = dp[pre]+1;
            } else if (hash[word[i]]-hash[word[i-1]] == 1) {
                dp[cur] = dp[pre]+1;
            } else if (word[i] == 'a') {
                dp[cur] = 1;
            } else {
                dp[cur] = 0;
            }
            if (word[i] == 'u') {
                result = max(result, dp[cur]);
            }
        }
        return result;
    }
};
