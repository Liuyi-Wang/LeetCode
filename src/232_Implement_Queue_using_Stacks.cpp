static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        in.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if (out.empty()) {
            dump();
        }
        int result = out.top();
        out.pop();
        return result;
    }
    
    /** Get the front element. */
    int peek() {
        if (out.empty()) {
            dump();
        }
        return out.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return in.empty() && out.empty();
    }
    
private:
    stack<int> in;
    stack<int> out;
    
    void dump() {
        while (!in.empty()) {
            out.push(in.top());
            in.pop();
        }
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
