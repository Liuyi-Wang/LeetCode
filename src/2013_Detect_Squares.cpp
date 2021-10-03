class DetectSquares {
public:
    DetectSquares() {
        d_x = vector<vector<int>>(1001, vector<int>());
        d_y = vector<set<int>>(1001, set<int>());
        d_count = vector<vector<int>>(1001, vector<int>(1001, 0));
    }
    
    void add(vector<int> point) {
        if (d_count[point[0]][point[1]] != 0) {
            ++d_count[point[0]][point[1]];
        } else {
            d_x[point[0]].push_back(point[1]);
            d_y[point[1]].insert(point[0]);
            ++d_count[point[0]][point[1]];
        }
    }
    
    int count(vector<int> point) {
        int result = 0;
        for (int i = 0; i < d_x[point[0]].size(); ++i) {
            int y = d_x[point[0]][i];
            if (point[1] == y) {
                continue;
            }
            if (d_y[point[1]].size() == 0) {
                continue;
            }
            int x = point[0]+(abs(point[1]-y));
            if (d_y[point[1]].find(x) != d_y[point[1]].end()) {
                if (d_count[x][y] != 0) {
                    result += d_count[x][y]*d_count[point[0]][y]*d_count[x][point[1]];
                }
            }
            x = point[0]-(abs(point[1]-y));
            if (d_y[point[1]].find(x) != d_y[point[1]].end()) {
                if (d_count[x][y] != 0) {
                    result += d_count[x][y]*d_count[point[0]][y]*d_count[x][point[1]];
                }
            }
        }
        return result;
    }
    
private:
    vector<vector<int>> d_x;
    vector<set<int>> d_y;
    vector<vector<int>> d_count;
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */
