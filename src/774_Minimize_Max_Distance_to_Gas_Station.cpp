class Solution {
public:
    bool valid(const vector<int>& stations, int K, double d) {
        for (int i = 1; i < stations.size(); ++i) {
            int k = double(stations[i]-stations[i-1])/d;
            K -= k;
            if (K < 0) {
                return false;
            }
        }
        return true;
    }
    
    double minmaxGasDist(vector<int>& stations, int K) {
        double begin = double(stations.back()-stations[0])/(K+stations.size()-1);
        double end = 0;
        for (int i = 1; i < stations.size(); ++i) {
            end = max(end, double(stations[i]-stations[i-1]));
        }
        while (begin+0.000006 < end) {
            double mid = begin+(end-begin)/2;
            if (valid(stations, K, mid)) {
                end = mid;
            } else {
                begin = mid;
            }
        }
        if (valid(stations, K, begin)) {
            return begin;
        }
        return end;
    }
};
