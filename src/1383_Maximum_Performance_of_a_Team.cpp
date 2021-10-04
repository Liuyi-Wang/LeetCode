class Solution {
public:
    struct greater_than {
        inline bool operator() (const vector<int>& v1, const vector<int>& v2) {
            return v1[0] > v2[0];
        }
    };
    
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        int M = 1e9+7;
        vector<vector<int>> v;
        for (int i = 0; i < speed.size(); ++i) {
            v.push_back({efficiency[i], speed[i]});
        }
        sort(v.begin(), v.end(), greater_than());
        long long sum = 0;
        long long result = 0;
        priority_queue<int, vector<int>, greater<int>> heap;
        for (int i = 0; i < v.size(); ++i) {
            if (heap.size() == k) {
                sum -= heap.top();
                heap.pop();
            }
            sum += v[i][1];
            heap.push(v[i][1]);
            result = max(result, sum*v[i][0]);
        }
        return result%M;
    }
};
