static const auto optimization = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class RecentCounter {
public:
    RecentCounter() {
    }
    
    int ping(int t) {
        d_t.push(t);
        while (!d_t.empty()) {
            if (d_t.front() < t-3000) {
                d_t.pop();
            } else {
                break;
            }
        }
        return d_t.size();
    }
private:
    queue<int> d_t;
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
