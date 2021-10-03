class Solution {
public:
    // implement find and union
    int find(unordered_map<int, int> &UF, int x) {
        if (x != UF[x]) {
            UF[x] = find(UF, UF[x]);
        }
        return UF[x];
    }

    // the name "merge" is used here since "union" is a reserved type in c++
    void merge(unordered_map<int, int> &UF, int x, int y) {
        if (UF.count(x) == 0) {
            UF[x] = x;
        }
        if (UF.count(y) == 0) {
            UF[y] = y;
        }
        UF[find(UF, x)] = find(UF, y);
    }

    vector<vector<int>> matrixRankTransform(vector<vector<int>> &matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        // link row and col together
        unordered_map<int, unordered_map<int, int>> UFs;
        //  UFs[v]: the Union-Find of value v
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int v = matrix[i][j];
                // union i to j
                merge(UFs[v], i, ~j);
            }
        }

        // put points into `value2index` dict, grouped by connection
        map<int, unordered_map<int, vector<pair<int, int>>>> value2index;
        // use ordered map to help us sort the key automatically
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int v = matrix[i][j];
                int f = find(UFs[v], i);
                value2index[v][f].push_back({i, j});
            }
        }

        // the required rank matrix
        vector<vector<int>> answer(m, vector<int>(n));
        vector<int> rowMax(m);  // rowMax[i]: the max rank in i row
        vector<int> colMax(n);  // colMax[j]: the max rank in j col
        for (auto v : value2index) {
            // update by connected points with same value
            for (auto entries : v.second) {
                auto points = entries.second;
                int rank = 1;
                for (auto point : points) {
                    rank =
                        max(rank,
                            max(rowMax[point.first], colMax[point.second]) + 1);
                }
                for (auto point : points) {
                    answer[point.first][point.second] = rank;
                    // update rowMax and colMax
                    rowMax[point.first] = max(rowMax[point.first], rank);
                    colMax[point.second] = max(colMax[point.second], rank);
                }
            }
        }
        return answer;
    }
};
