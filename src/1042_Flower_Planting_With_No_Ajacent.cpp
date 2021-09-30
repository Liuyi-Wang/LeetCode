class Solution {
public:
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        vector<int> result(N, 0);
        vector<vector<int>> connected(N+1, vector<int>());
        for (auto p:paths) {
            connected[p[0]].push_back(p[1]);
            connected[p[1]].push_back(p[0]);
        }
        for (int l = 1; l <= N;) {
            if (result[l-1]) {
                ++l;
                continue;
            }
            vector<bool> planted(4, false);
            for (auto neighbor:connected[l]) {
                if (0 != result[neighbor-1]) {
                    planted[result[neighbor-1]-1] = true;    
                }
            }
            int f = 0;
            for (int i = 0; i < planted.size(); ++i) {
                if (!planted[i]) {
                    f = i+1;
                    break;
                }
            }
            result[l-1] = f;
        }
        return result;
    }
};
