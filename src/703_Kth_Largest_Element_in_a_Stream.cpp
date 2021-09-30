static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class KthLargest {
public:
    struct greater_than {
        inline bool operator() (int i1, int i2) {
            return i1 > i2;
        }
    };
    
    KthLargest(int k, vector<int>& nums) {
        d_k = k;
        for (auto n:nums) {
            insert(n);
        }
    }
    
    int add(int val) {
        insert(val);
        return d_heap.top();
    }
    
private:
    priority_queue<int, vector<int>, greater_than> d_heap;
    int d_k;
    
    void insert(int val) {
        if (d_heap.size() < d_k) {
            d_heap.push(val);
        } else if (d_heap.size() == d_k && d_heap.top() < val) {
            d_heap.pop();
            d_heap.push(val);
        }
        
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
