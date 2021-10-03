class Solution {
public:
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        vector<double> degrees;
        int count = 0;
        double view = double(angle)*M_PI/180;
        for (auto point:points) {
            if (point[0] == location[0] && point[1] == location[1]) {
                ++count;
                continue;
            }
            double dx = point[0]-location[0];
            double dy = point[1]-location[1];
            double degree = atan2(dy, dx);
            degrees.push_back(degree);
        }
        sort(degrees.begin(), degrees.end());
        int size = degrees.size();
        for (int i = 0; i < size; ++i) {
            if (degrees[i] <= angle) {
                degrees.push_back(2*M_PI+degrees[i]);
            } else {
                break;
            }
        }
        int result = 0;
        int r = 0;
        for (int l = 0; l < degrees.size(); ++l) {
            while (r < degrees.size() && degrees[r]-degrees[l] <= view + 0.00001) {
                ++r;
            }
            result = max(result, r-l);
        }
        return result+count;
    }
};
