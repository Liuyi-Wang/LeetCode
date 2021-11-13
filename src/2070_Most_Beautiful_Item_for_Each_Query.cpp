class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        map<int, int> hash;
        for (auto item:items) {
            hash[item[0]] = max(hash[item[0]], item[1]);
        }
        map<int, int>::iterator it = hash.begin();
        int high = it->second;
        ++it;
        for (; it != hash.end(); ++it) {
            it->second = max(it->second, high);
            high = it->second;
        }
        vector<int> result(queries.size(), 0);
        for (int i = 0; i < queries.size(); ++i) {
            it = hash.upper_bound(queries[i]);
            if (it != hash.begin()) {
                --it;
                result[i] = it->second;
            }
        }
        return result;
    }
};
