class Solution {
public:
    struct Dwb {
        int distance;    
        int worker;
        int bike;
        Dwb(int d, int w, int b) : distance(d), worker(w), bike(b) {}
    };
    
    struct less_than {
        inline bool operator() (const Dwb& dwb1, const Dwb& dwb2) {
            if (dwb1.distance != dwb2.distance) {
                return dwb1.distance < dwb2.distance;
            }
            if (dwb1.worker != dwb2.worker) {
                return dwb1.worker < dwb2.worker;
            }
            return dwb1.bike < dwb2.bike;
        }
    };
    
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        int n = workers.size(), m = bikes.size();
        vector<int> result(n, 0);
        vector<Dwb> dwbs;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                dwbs.push_back(Dwb(abs(workers[i][0]-bikes[j][0])+abs(workers[i][1]-bikes[j][1]), i, j));
            }
        }
        sort(dwbs.begin(), dwbs.end(), less_than());
        vector<bool> uw(n, false);
        vector<bool> ub(m, false);
        int count = 0;
        for (int i = 0; i < dwbs.size() && count < n; ++i) {
            if (!uw[dwbs[i].worker] && !ub[dwbs[i].bike]) {
                uw[dwbs[i].worker] = true;
                ub[dwbs[i].bike] = true;
                result[dwbs[i].worker] = dwbs[i].bike;
                ++count;
            }
        }
        return result;   
    }
};
