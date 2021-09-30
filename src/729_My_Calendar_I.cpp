static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class MyCalendar {
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        map<int, int>::iterator it = d_m.lower_bound(start);
        if (it != d_m.end() && end > it->first) {
            return false;
        }
        if (it != d_m.begin()) {
            map<int, int>::iterator it_t = it;
            --it_t;
            if (it_t->second > start) {
                return false;
            }
        }
        d_m[start] = end;
        return true;
    }
    
private:
    map<int, int> d_m;
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
