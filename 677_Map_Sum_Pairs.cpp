static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class MapSum {
public:
    /** Initialize your data structure here. */
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        if (v.find(key) == v.end()) {
            for (int i = 1; i <= key.size(); ++i) {
                pre[key.substr(0, i)].push_back(key);
            }
        }
        v[key] = val;
    }
    
    int sum(string prefix) {
        int result = 0;
        for (auto s:pre[prefix]) {
            result += v[s];
        }
        return result;
    }
    
private:
    unordered_map<string, int> v;
    unordered_map<string, vector<string>> pre;
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
