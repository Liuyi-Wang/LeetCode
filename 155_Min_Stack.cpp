static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        d_s.push(x);
        if (d_m.empty() || x <= d_m.top()) {
            d_m.push(x);
        }
    }
    
    void pop() {
        if (!d_m.empty() && d_m.top() == d_s.top()) {
            d_m.pop();
        }
        d_s.pop();
    }
    
    int top() {
        return d_s.top();
    }
    
    int getMin() {
        return d_m.top();
    }

private:
    stack<int> d_s;
    stack<int> d_m;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
