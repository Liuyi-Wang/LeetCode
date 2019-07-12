class Solution {
public:
    struct less_than {
        inline bool operator() (const pair<int, int>& left,
                                const pair<int, int>& right) {
            if (left.first < right.first) {
                return true;
            }
            if (left.first > right.first) {
                return false;
            }
            return left.second < right.second;
        }    
    };
    
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<pair<int,int> > stations;
        for (int i = 0; i < trips.size(); ++i) {
            stations.push_back(pair<int, int>(trips[i][1], trips[i][0]));
            stations.push_back(pair<int, int>(trips[i][2], -trips[i][0]));
        }
        sort(stations.begin(), stations.end(), less_than());
        int passengers = 0;
        for (int i = 0; i < stations.size(); ++i) {
            passengers += stations[i].second;
            if (passengers > capacity) {
                return false;
            }
        }
        return true;
    }
};
