/**
 *  Time:
 *  O(n)
 *  Space:
 *  O(n)
 */
class FirstUnique {
public:
    FirstUnique(vector<int>& nums) {
        for (auto num:nums) {
            d_q.push(num);
            ++d_counts[num];
        }
    }
    
    int showFirstUnique() {
        while (!d_q.empty() && d_counts[d_q.front()] > 1) {
            d_q.pop();
        }
        if (d_q.empty()) {
            return -1;
        }
        return d_q.front();
    }
    
    void add(int value) {
        ++d_counts[value];
        if (d_counts[value] == 1) {
            d_q.push(value);
        }
    }
    
private:
    unordered_map<int, int> d_counts;
    queue<int> d_q;
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */
