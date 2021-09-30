static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> result(n, 0);
        stack<int> lastId;
        int start;
        for (const auto& l:logs) {
            stringstream ss(l);
            string t;
            int id;
            bool isStart;
            int time;
            int i = 0;
            while (getline(ss, t, ':')) {
                if (0 == i) {
                    id = atoi(t.c_str());    
                } else if (1 == i) {
                    isStart = t=="start"?true:false; 
                } else if (2 == i) {
                    time = atoi(t.c_str());
                }
                ++i;
            }
            if (isStart) {
                if (!lastId.empty()) {
                    result[lastId.top()] += time-start;       
                }
                start = time;
                lastId.push(id);
            } else {
                result[id] += time-start+1;
                lastId.pop();
                start = time+1;
            }
        }
        return result;
    }
};
