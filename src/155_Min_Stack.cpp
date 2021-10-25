/**
 *  Intuition
 *  Only the top element of stack can be operated on.
 */
class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int val) {
        d_stack.push(val);
        if (d_min.empty() || d_min.top().first > val) {
            d_min.push({val, 1});
        } else if (!d_min.empty() && d_min.top().first == val) {
            ++d_min.top().second;
        }
    }
    
    void pop() {
        if (!d_min.empty() && d_min.top().first == d_stack.top()) {
            --d_min.top().second;
            if (d_min.top().second == 0) {
                d_min.pop();
            }
        }
        d_stack.pop();
    }
    
    int top() {
        return d_stack.top();
    }
    
    int getMin() {
        return d_min.top().first;
    }
    
private:
    stack<int> d_stack;
    stack<pair<int, int>> d_min;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
