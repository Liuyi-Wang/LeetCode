static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    struct less_than {
        inline bool operator() (const vector<int>& v1,
                                const vector<int>& v2) {
            if (v1[0] == v2[0]) {
                return v1[1] > v2[1];
            }
            return v1[0] > v2[0];
        }    
    };
    
    double minAreaFreeRect(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), less_than());
        map<double, vector<vector<int>>> hash;
        for (int i = 0; i < points.size(); ++i) {
            for (int j = i+1; j < points.size(); ++j) {
                if (points[j][0] == points[i][0]) {
                    continue;
                }
                double s = double(points[j][1]-points[i][1])/(points[j][0]-points[i][0]);
                vector<int> v = points[i];
                v.insert(v.begin(), points[j].begin(), points[j].end());
                hash[s].push_back(v);
            }
        }
        double result = 0;
        bool find = false;
        for (map<double, vector<vector<int>>>::iterator it = hash.begin(); it != hash.end(); ++it) {
            for (int i = 0; i < it->second.size(); ++i) {
                for (int j = i+1; j < it->second.size(); ++j) {
                    int l1 = (it->second[i][0]-it->second[i][2])*(it->second[i][0]-it->second[i][2])+
                             (it->second[i][1]-it->second[i][3])*(it->second[i][1]-it->second[i][3]);
                    int l2 = (it->second[j][0]-it->second[j][2])*(it->second[j][0]-it->second[j][2])+
                             (it->second[j][1]-it->second[j][3])*(it->second[j][1]-it->second[j][3]);
                    if (l1 != l2) {
                        continue;
                    }
                    if ((it->second[i][1]-it->second[j][1])*(it->second[j][3]-it->second[j][1])+
                        (it->second[i][0]-it->second[j][0])*(it->second[j][2]-it->second[j][0]) != 0) {
                        continue;
                    }
                    int l = (it->second[i][0]-it->second[j][0])*(it->second[i][0]-it->second[j][0])+
                            (it->second[i][1]-it->second[j][1])*(it->second[i][1]-it->second[j][1]);
                    if (!find) {
                        find = true;
                        result = sqrt(double(l1))*sqrt(double(l));
                    } else {
                        result = min(result, sqrt(double(l1))*sqrt(double(l)));
                    }
                }
            }
        }
        if (!find) {
            return 0;
        }
        return result;
    }
};
