class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<int> candies(n+1, 0);
        set<int> c_index;
        for (int i = 1; i <= n; ++i) {
            candies[i] = candies[i-1];
            if (s[i-1] == '|') {
                c_index.insert(i-1);
                ++candies[i];
            }
            //cout << candies[i] << ",";
        }
        //cout << endl;
        vector<int> result(queries.size(), 0);
        for (int i = 0; i < queries.size(); ++i) {
            set<int>::iterator low = c_index.lower_bound(queries[i][0]);
            if (low == c_index.end()) {
                continue;
            }
            set<int>::iterator high = c_index.upper_bound(queries[i][1]);
            if (high == c_index.begin()) {
                continue;
            }
            --high;
            if (*low >= *high) {
                continue;
            }
            int c = candies[*high+1]-candies[*low+1];
            //result[i] = max(0, (*high)-(*low)-c);
            //cout << i << "=>" << c << endl;
            result[i] = (*high)-(*low)-c;
        }
        return result;
    }
};
