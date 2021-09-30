static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (d_max_q.empty()) {
            d_max_q.push(num);
        } else if (!d_max_q.empty() && d_max_q.top() <= num) {
            d_min_q.push(num);
        } else {
            d_max_q.push(num);
        }
        if (abs((int)d_max_q.size()-(int)d_min_q.size()) <= 1) {
            return;
        }
        if (d_max_q.size() > d_min_q.size()) {
            int n = d_max_q.top();
            d_max_q.pop();
            d_min_q.push(n);
            return;
        }
        if (d_max_q.size() < d_min_q.size()) {
            int n = d_min_q.top();
            d_min_q.pop();
            d_max_q.push(n);
            return;
        }
    }
    
    double findMedian() {
        if (d_max_q.size() == d_min_q.size()) {
            return ((double)d_max_q.top()+(double)d_min_q.top())/2;
        } else if (d_max_q.size() > d_min_q.size()) {
            return d_max_q.top();
        } else {
            return d_min_q.top();
        }
        return 0;
    }
    
private:
    priority_queue<int> d_max_q;
    priority_queue<int, vector<int>, greater<int>> d_min_q;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
