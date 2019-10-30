static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class LogSystem {
public:
    LogSystem() {
        d_g["Year"] = 4;
        d_g["Month"] = 7;
        d_g["Day"] = 10;
        d_g["Hour"] = 13;
        d_g["Minute"] = 16;
        d_g["Second"] = 19;
    }
    
    void put(int id, string timestamp) {
        d_log.push_back(pair<string, int>(timestamp, id));
    }
    
    vector<int> retrieve(string s, string e, string gra) {
        int len = d_g[gra];
        vector<int> result;
        for (const auto& log:d_log) {
            if (s.substr(0, len) <= log.first.substr(0, len) &&
                log.first.substr(0, len) <= e.substr(0, len)) {
                result.push_back(log.second);
            }
        }
        return result;
    }
    
private:
    vector<pair<string, int>> d_log;
    unordered_map<string, int> d_g;
};

/**
 * Your LogSystem object will be instantiated and called as such:
 * LogSystem* obj = new LogSystem();
 * obj->put(id,timestamp);
 * vector<int> param_2 = obj->retrieve(s,e,gra);
 */
