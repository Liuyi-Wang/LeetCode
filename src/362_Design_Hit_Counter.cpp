static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class HitCounter {
public:
    /** Initialize your data structure here. */
    HitCounter() {
        
    }
    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        if (d_m.find(timestamp) == d_m.end()) {
            d_q.push(timestamp);
        }
        ++d_m[timestamp];
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        while (!d_q.empty()) {
            if (d_q.front() <= timestamp-300) {
                d_m.erase(d_m.find(d_q.front()));
                d_q.pop();
            } else {
                break;
            }
        }
        int result = 0;
        for (unordered_map<int, int>::iterator it = d_m.begin(); it != d_m.end(); ++it) {
            result += it->second;
        }
        return result;
    }
    
private:
    queue<int> d_q;
    unordered_map<int, int> d_m;
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */
