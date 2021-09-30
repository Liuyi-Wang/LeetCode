static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    Solution(vector<int>& nums) {
        n = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return n;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> m = n;
        for (int i = 1; i < m.size(); ++i) {
            swap(m[rand()%(i+1)], m[i]);
        }
        return m;
    }
    
private:
    vector<int> n;    
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
