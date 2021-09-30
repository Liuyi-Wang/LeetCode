static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        d_i = {-1, 0, 1, 0};
        d_j = {0, 1, 0, -1};
        for (int i = 0; i < rooms.size(); ++i) {
            for (int j = 0; j < rooms[i].size(); ++j) {
                if (0 == rooms[i][j]) {
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    int d = 1;
                    while (!q.empty()) {
                        int size = q.size();
                        for (int m = 0; m < size; ++m) {
                            int ii = q.front().first;
                            int jj = q.front().second;
                            q.pop();
                            for (int n = 0; n < d_i.size(); ++n) {
                                int I = ii + d_i[n];
                                int J = jj + d_j[n];
                                if (I < 0 || J < 0 || I >= rooms.size() || J >= rooms[i].size()) {
                                    continue;
                                }
                                if (rooms[I][J] <= d) {
                                    continue;    
                                }
                                rooms[I][J] = d;
                                q.push({I, J});
                            }
                        }
                        ++d;
                    } 
                }       
            }
        }
    }
    
private:
    vector<int> d_i;
    vector<int> d_j;
};
