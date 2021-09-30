class Solution {
public:
    vector<int> gridIllumination(int N, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        set<pair<int, int>> s;
        unordered_map<int, int> h, v, p, n;
        for (auto l:lamps) {
            int i = l[0], j = l[1];
            s.insert(pair<int, int>(i, j));
            ++h[i];
            ++v[j];
            ++p[i+j];
            ++n[i-j];
        }
        vector<int> result(queries.size(), 0);
        for (int k = 0; k < queries.size(); ++k) {
            int i = queries[k][0], j = queries[k][1];
            if (h[i] > 0 || v[j] > 0 || p[i+j] > 0 || n[i-j] > 0) {
                result[k] = 1;
            }
            if (s.find(pair<int, int>(i-1, j-1)) != s.end()) {
                s.erase(s.find(pair<int, int>(i-1, j-1)));
                --h[i-1];
                --v[j-1];
                --p[i+j-2];
                --n[i-j];
            }
            if (s.find(pair<int, int>(i-1, j)) != s.end()) {
                s.erase(s.find(pair<int, int>(i-1, j)));
                --h[i-1];
                --v[j];
                --p[i+j-1];
                --n[i-j-1];
            }
            if (s.find(pair<int, int>(i-1, j+1)) != s.end()) {
                s.erase(s.find(pair<int, int>(i-1, j+1)));
                --h[i-1];
                --v[j+1];
                --p[i+j];
                --n[i-j-2];
            }
            if (s.find(pair<int, int>(i, j-1)) != s.end()) {
                s.erase(s.find(pair<int, int>(i, j-1)));
                --h[i];
                --v[j-1];
                --p[i+j-1];
                --n[i-j+1];
            }
            if (s.find(pair<int, int>(i, j)) != s.end()) {
                s.erase(s.find(pair<int, int>(i, j)));
                --h[i];
                --v[j];
                --p[i+j];
                --n[i-j];
            }
            if (s.find(pair<int, int>(i, j+1)) != s.end()) {
                s.erase(s.find(pair<int, int>(i, j+1)));
                --h[i];
                --v[j+1];
                --p[i+j+1];
                --n[i-j-1];
            }
            if (s.find(pair<int, int>(i+1, j-1)) != s.end()) {
                s.erase(s.find(pair<int, int>(i+1, j-1)));
                --h[i+1];
                --v[j-1];
                --p[i+j];
                --n[i-j+2];
            }
            if (s.find(pair<int, int>(i+1, j)) != s.end()) {
                s.erase(s.find(pair<int, int>(i+1, j)));
                --h[i+1];
                --v[j];
                --p[i+j+1];
                --n[i-j+1];
            }
            if (s.find(pair<int, int>(i+1, j+1)) != s.end()) {
                s.erase(s.find(pair<int, int>(i+1, j+1)));
                --h[i+1];
                --v[j+1];
                --p[i+j+2];
                --n[i-j];
            }
        }
        return result;
    }
};
