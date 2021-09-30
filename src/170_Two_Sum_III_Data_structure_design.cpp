static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class TwoSum {
public:
    /** Initialize your data structure here. */
    TwoSum() {
        d_max = INT_MIN;
        d_min = INT_MAX;
    }
    
    /** Add the number to an internal data structure.. */
    void add(int number) {
        ++d_n[number];
        if (number > d_max) {
            d_max = number;
        }
        if (number < d_min) {
            d_min = number;
        }
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        if (0 == d_n.size()) {
            return false;
        }
        if (value > 2*d_max || value < 2*d_min) {
            return false;
        }
        for (unordered_map<int, int>::iterator it = d_n.begin(); it != d_n.end(); ++it) {
            if (value == 2*it->first) {
                if (it->second >= 2) {
                    return true;
                }
                continue;
            }
            if (d_n.find(value-it->first) != d_n.end()) {
                return true;
            }
        }
        return false;
    }

private:
    unordered_map<int, int> d_n;
    int d_max;
    int d_min;
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */
