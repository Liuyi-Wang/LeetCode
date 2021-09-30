class Solution {
public:
    struct more_than {
        inline bool operator() (const pair<int, int>& p1,
                                const pair<int, int>& p2) {
            if (p1.first > p2.first) {
                return true;
            } else if (p1.first < p2.first) {
                return false;
            } else {
                return p1.second < p2.second;
            }
        }
    };
    
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int num_wanted, int use_limit) {
        vector<pair<int, int> > items;
        vector<int> counts(20001, 0);
        for (int i = 0; i < values.size(); ++i) {
            items.push_back(pair<int, int>(values[i], labels[i]));
        }
        sort(items.begin(), items.end(), more_than());
        int sum = 0, num = 0;
        for (int i = 0; i < items.size(); ++i) {
            if (num >= num_wanted) {
                break;
            }
            if (counts[items[i].second] >= use_limit) {
                continue;
            }
            sum += items[i].first;
            ++num;
            ++counts[items[i].second];
        }
        return sum;
    }
};
