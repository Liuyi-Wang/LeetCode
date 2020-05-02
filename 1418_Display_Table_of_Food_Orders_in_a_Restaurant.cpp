class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        map<pair<int, string>, int> counts;
        set<int> tables;
        set<string> names;
        for (const auto &order:orders) {
            ++counts[{atoi(order[1].c_str()), order[2]}];
            tables.insert(atoi(order[1].c_str()));
            names.insert(order[2]);
        }
        vector<vector<string>> result;
        vector<string> header = {"Table"};
        for (set<string>::iterator it = names.begin(); it != names.end(); ++it) {
            header.push_back(*it);
        }
        result.push_back(header);
        for (set<int>::iterator tit = tables.begin(); tit != tables.end(); ++tit) {
            vector<string> row = {to_string(*tit)};
            for (set<string>::iterator it = names.begin(); it != names.end(); ++it) {
                row.push_back(to_string(counts[{*tit, *it}]));
            }
            result.push_back(row);
        }
        return result;
    }
};
