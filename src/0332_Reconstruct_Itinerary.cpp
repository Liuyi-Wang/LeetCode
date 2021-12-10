/**
 *  Time:
 *  O(ElogE+E)
 *  Space:
 *  O(E)
 */
class Solution {
    unordered_map<string, vector<string>> to;
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (auto t:tickets) {
            to[t[0]].push_back(t[1]);
        }
        
        auto cmp = [](const string& s1, const string& s2) {
            return s1 > s2;
        };
        for (auto &it:to) {
            sort(it.second.begin(), it.second.end(), cmp);
        }
        
        vector<string> result;
        dfs("JFK", result);
        reverse(result.begin(), result.end());
        return result;
    }
    
    void dfs(string start, vector<string>& path) {
        while (to[start].size() > 0) {
            string next = to[start].back();
            to[start].pop_back();
            dfs(next, path);
        }
        path.push_back(start);
    }
};
