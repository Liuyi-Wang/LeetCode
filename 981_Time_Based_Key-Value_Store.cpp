class TimeMap {
public:
    /** Initialize your data structure here. */
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        d_time[key].push_back(timestamp);
        d_value[key].push_back(value);
    }
    
    string get(string key, int timestamp) {
        if (d_time.find(key) == d_time.end()) {
            return "";
        }
        if (timestamp < d_time[key][0]) {
            return "";
        }
        if (timestamp >= d_time[key].back()) {
            return d_value[key].back();
        }
        int begin = 0, end = d_time.size()-1;
        while (begin < end-1) {
            
        }
        if (begin == end) {
            return d_value[key][begin];
        }
        if (begin == end-1) {
            if (d_time[key][end-1] <= timestamp) {
                return d_value[key][end-1];
            }
            return d_value[key][begin];
        }
        return "";
    }
private:
    unordered_map<string, vector<int>>    d_time;
    unordered_map<string, vector<string>> d_value;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
