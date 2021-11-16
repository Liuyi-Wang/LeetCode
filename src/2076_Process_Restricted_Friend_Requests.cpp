/**
 *  Time:
 *  O(m*k), m = requests.size, k = restriction.size
 *  Space:
 *  O(n)
 */
class Solution {
public:
    int find_root(int a) {
        int r = a;
        while (d_r[r] != r) {
            r = d_r[r];
        }
        while (a != r) {
            int t = d_r[a];
            d_r[a] = r;
            a = t;
        }
        return r;
    }
    
    void merge(int a, int b) {
        int ra = find_root(a);
        int rb = find_root(b);
        if (ra != rb) {
            d_r[ra] = rb;
        }
    }
    
    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
        d_r = vector<int>(n, 0);
        for (int i = 0; i < n; ++i) {
            d_r[i] = i;
        }
        vector<bool> result(requests.size(), false);
        for (int i = 0; i < requests.size(); ++i) {
            vector<int> request = requests[i];
            int ra = find_root(request[0]);
            int rb = find_root(request[1]);
            if (ra == rb) {
                result[i] = true;
                continue;
            }
            bool valid = true;
            for (auto& restriction:restrictions) {
                if ((find_root(restriction[0]) == ra && find_root(restriction[1]) == rb) || 
                    (find_root(restriction[0]) == rb && find_root(restriction[1]) == ra)) {
                    valid = false;
                    break;
                } 
            }
            if (valid) {
                result[i] = true;
                merge(request[0], request[1]);
            }
        }
        return result;
    }
    
private:
    vector<int> d_r;
};
