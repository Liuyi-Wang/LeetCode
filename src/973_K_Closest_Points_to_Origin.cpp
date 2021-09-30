class Solution {
public:
    struct less_than {
        inline bool operator() (const vector<int>& v1,
                                const vector<int>& v2) {
            return v1[0]*v1[0]+v1[1]*v1[1] < v2[0]*v2[0]+v2[1]*v2[1];
        }
    };   

    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        map<long long, vector<vector<int>>> hash;
        int n = points.size();
        vector<vector<int>> result(points.begin(), points.begin()+K);
        make_heap(result.begin(), result.end(), less_than());
        for (int i = K; i < points.size(); ++i) {
            result.push_back(points[i]);
            push_heap(result.begin(), result.end(), less_than());
            pop_heap(result.begin(), result.end(), less_than());
            result.pop_back();
        }
        return result;
    }
};
