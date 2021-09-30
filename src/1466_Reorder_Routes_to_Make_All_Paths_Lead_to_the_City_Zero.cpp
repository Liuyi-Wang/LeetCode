class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        map<int, vector<int>> cityIn;
        map<int, vector<int>> cityOut;
        for (auto connection:connections) {
            cityOut[connection[0]].push_back(connection[1]);
            cityIn[connection[1]].push_back(connection[0]);
        }
        queue<int> q;
        q.push(0);
        int result = 0;
        vector<bool> v(n, false);
        v[0] = true;
        while (!q.empty()) {
            int m = q.size();
            for (int i = 0; i < m; ++i) {
                int c = q.front();
                q.pop();
                for (auto city:cityOut[c]) {
                    if (v[city] == false) {
                        v[city] = true;
                        q.push(city);
                        ++result;
                    }
                }
                for (auto city:cityIn[c]) {
                    if (v[city] == false){
                        v[city] = true;
                        q.push(city);
                    }
                }
            }
        }
        return result;
    }
};
