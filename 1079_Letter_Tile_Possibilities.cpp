class Solution {
public:
    int solve(vector<int>& counts) {
        int result = 0;
        for (int i = 0; i < counts.size(); ++i) {
            if (0 == counts[i]) {
                continue;
            }
            --counts[i];
            ++result;
            result += solve(counts);
            ++counts[i];
        }
        return result;
    }
    
    int numTilePossibilities(string tiles) {
        vector<int> counts(26, 0);
        for (auto c:tiles) {
            counts[c-'A'] += 1;
        }
        return solve(counts);
    }
};
