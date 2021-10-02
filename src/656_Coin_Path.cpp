class Solution {
public:
    vector<int> cheapestJump(vector<int>& coins, int maxJump) {
        if (coins.back() == -1) {
            return {};
        }
        int n = coins.size();
        if (n == 1) {
            return {1};
        }
        vector<int> cost(n, -1);
        vector<int> next(n, -1);
        for (int i = n-2; i >= 0; --i) {
            if (coins[i] == -1) {
                continue;
            }
            for (int j = 1; j <= maxJump && i+j < n; ++j) {
                if (i+j == n-1) {
                    if (cost[i] == -1 || cost[i] > coins[i]) {
                        cost[i] = coins[i];
                        next[i] = i+j;
                    }
                    continue;
                }
                if (cost[i+j] == -1) {
                    continue;
                }
                if (cost[i] == -1 || cost[i] > coins[i]+cost[i+j]) {
                    cost[i] = coins[i]+cost[i+j];
                    next[i] = i+j;
                }
            }
        }
        if (cost[0] == -1) {
            return {};
        }
        vector<int> result = {1};
        while (next[result.back()-1] != -1) {
            result.push_back(next[result.back()-1]+1);
        }
        return result;
    }
};
