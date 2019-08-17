class StockSpanner {
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        int span = 1;
        while (!d_p.empty() && d_p.top().first <= price) {
            span += d_p.top().second;
            d_p.pop();
        }
        d_p.push(pair<int, int>(price, span));
        return span;
    }
private:
    stack<pair<int, int>> d_p;
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
