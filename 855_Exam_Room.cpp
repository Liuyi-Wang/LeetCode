static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class ExamRoom {
public:
    ExamRoom(int N) {
        d_n = N;
    }
    
    int seat() {
        if (0 == d_s.size()) {
            d_s.insert(0);
            return 0;
        }
        set<int>::iterator it = d_s.begin();
        int dist = *it;
        int pos = 0;
        int last = *it;
        for (; it != d_s.end(); ++it) {
            if (dist < (*it-last)/2) {
                dist = (*it-last)/2;
                pos = last + dist;
            }
            last = *it;
        }
        if (dist < d_n-1-last) {
            pos = d_n-1;
        }
        d_s.insert(pos);
        return pos;
    }
    
    void leave(int p) {
        d_s.erase(d_s.find(p));
    }

private:
    set<int> d_s;
    int d_n;
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(N);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */
