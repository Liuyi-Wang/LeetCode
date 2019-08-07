class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> trusted(N+1, 0);
        for (auto t:trust) {
            trusted[t[0]] = -1;
            ++trusted[t[1]];
        }
        for (int i = 1; i <= N; ++i) {
            if (N-1 == trusted[i]) {
                return i;
            }    
        }
        return -1;
    }
};
