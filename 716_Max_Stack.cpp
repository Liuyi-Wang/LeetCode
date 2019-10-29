static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class MaxStack {
public:
    /** initialize your data structure here. */
    MaxStack() {
        
    }
    
    void push(int x) {
        if (d_m.empty() || d_m.top() <= x) {
            d_m.push(x);
        }
        d_s.push(x);
    }
    
    int pop() {
        int result = d_s.top();
        d_s.pop();
        if (result == d_m.top()) {
            d_m.pop();
        }
        return result;
    }
    
    int top() {
        return d_s.top();
    }
    
    int peekMax() {
        return d_m.top();
    }
    
    int popMax() {
        stack<int> t;
        while (d_s.top() != d_m.top()) {
            t.push(d_s.top());
            d_s.pop();
        }
        int result = d_m.top();
        d_m.pop();
        d_s.pop();
        while (!t.empty()) {
            push(t.top());
            t.pop();
        }
        return result;
    }
    
private:
    stack<int> d_s;
    stack<int> d_m;
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */
