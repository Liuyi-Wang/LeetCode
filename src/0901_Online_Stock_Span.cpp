/**
 *  Time:
 *  O(n)
 *  Space:
 *  O(n)
 */
class StockSpanner {
    stack<pair<int, int>> stk;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        int result = 1;
        while (!stk.empty() && stk.top().first <= price) {
            result += stk.top().second;
            stk.pop();
        }
        stk.push({price, result});
        return result;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
