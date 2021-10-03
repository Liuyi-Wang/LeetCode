class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        int n = cars.size();
        stack<pair<double, int>> stk;
        vector<double> result(n, -1);
        stk.push({0, cars.back()[1]});
        for (int i = n-2; i >= 0; --i) {
            double diff = cars[i+1][0]-cars[i][0];
            while (!stk.empty() && stk.top().second >= cars[i][1]) {
                pair<double, int> p = stk.top();
                stk.pop();
                if (stk.empty()) {
                    break;
                }
                int dv = p.second-cars[i][1];
                double dt = stk.top().first-p.first;
                diff += dv*dt;
            }
            if (stk.empty()) {
                stk.push({0, cars[i][1]});
                continue;
            }
            vector<pair<double, int>> v;
            int speed = cars[i][1];
            v.push_back({0, speed});
            while (!stk.empty()) {
                pair<double, int> p = stk.top();
                stk.pop();
                int dv = speed-p.second;
                if (dv == 0) {
                    continue;
                }
                if (stk.empty()) {
                    double t = diff/dv;
                    v.push_back({p.first+t, p.second});
                    result[i] = p.first+t;
                    break;
                }
                double dt = stk.top().first-p.first;
                if (diff <= dv*dt) {
                    double t = diff/dv;
                    v.push_back({p.first+t, p.second});
                    result[i] = p.first+t;
                    break;
                }
                diff -= dv*dt;
            }
            for (int i = (int)v.size()-1; i >= 0; --i) {
                stk.push(v[i]);
            }
        }
        return result;
    }
};
