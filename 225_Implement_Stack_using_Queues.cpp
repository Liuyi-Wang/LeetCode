static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        queue<int> q;
        while (!s.empty()) {
            q.push(s.front());
            s.pop();
        }
        s.push(x);
        while (!q.empty()) {
            s.push(q.front());
            q.pop();
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int result = s.front();
        s.pop();
        return result;
    }
    
    /** Get the top element. */
    int top() {
        return s.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return s.empty();
    }
    
private:
    queue<int> s;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
