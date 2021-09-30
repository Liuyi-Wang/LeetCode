static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class FreqStack {
public:
    FreqStack() {
        d_f = 0;
    }
    
    void push(int x) {
        ++d_nf[x];
        int f = d_nf[x];
        d_f = max(d_f, f);
        d_fn[f].push(x);
    }
    
    int pop() {
        while (d_fn.find(d_f) == d_fn.end()) {
            --d_f;
        }
        int result = d_fn[d_f].top();
        d_fn[d_f].pop();
        --d_nf[result];
        if (d_fn[d_f].empty()) {
            d_fn.erase(d_fn.find(d_f));
            --d_f;
        }
        return result;
    }
    
private:
    unordered_map<int, stack<int>> d_fn;
    unordered_map<int, int> d_nf;
    int d_f;
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */
