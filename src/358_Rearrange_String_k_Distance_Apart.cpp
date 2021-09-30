static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    string rearrangeString(string s, int k) {
        if (k <= 1) {
            return s;
        }
        unordered_map<char, int> counts;
        for (const auto &c:s) {
            ++counts[c];
        }
        priority_queue<pair<int, char>> q;
        for (unordered_map<char, int>::iterator it = counts.begin(); it != counts.end(); ++it) {
            q.push({it->second, it->first});
        }
        string result;
        int len = s.size();
        while (!q.empty()) {
            vector<pair<int, char>> v;
            int batch = min(k, len);
            for (int i = 0; i < batch; ++i) {
                if (q.empty()) {
                    return "";
                }
                pair<int, char> p = q.top();
                q.pop();
                result.push_back(p.second);
                --len;
                --p.first;
                if (p.first > 0) {
                    v.push_back(p);
                }
            }
            for (const auto &p:v) {
                q.push(p);
            }
        }
        return result;
    }
};
