/**
 *  Time:
 *  O(n)
 *  Space:
 *  O(n)
 */
class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string, unordered_set<string>> hash;
        unordered_map<string, int> counts;
        for (int i = 0; i < ingredients.size(); ++i) {
            for (auto ingredient:ingredients[i]) {
                hash[ingredient].insert(recipes[i]);
                ++counts[recipes[i]];
            }
        }
        queue<string> q;
        for (auto supply:supplies) {
            q.push(supply);
        }
        vector<string> result;
        while (!q.empty()) {
            string s = q.front();
            q.pop();
            for (auto str:hash[s]) {
                --counts[str];
                if (counts[str] == 0) {
                    q.push(str);
                    result.push_back(str);
                }
            }
        }
        return result;
    }
};
