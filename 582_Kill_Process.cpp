static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        unordered_map<int, vector<int>> ptoc;
        for (int i = 0; i < pid.size(); ++i) {
            ptoc[ppid[i]].push_back(pid[i]);
        }
        vector<int> result = {kill};
        queue<int> q;
        q.push(kill);
        while (!q.empty()) {
            kill = q.front();
            q.pop();
            if (ptoc.find(kill) != ptoc.end()) {
                for (auto c:ptoc[kill]) {
                    result.push_back(c);
                    q.push(c);
                }
            }
        }
        return result;
    }
};
