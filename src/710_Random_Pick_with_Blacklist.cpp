static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    Solution(int N, vector<int>& blacklist) {
        d_count = N-blacklist.size();
        int last = N-blacklist.size();
        sort(blacklist.begin(), blacklist.end());
        unordered_set<int> s;
        for (int i = blacklist.size()-1; i >= 0; --i) {
            if (blacklist[i] > N-1-blacklist.size()) {
                s.insert(blacklist[i]);   
            } else {
                while (s.find(last) != s.end()) {
                    ++last;
                }
                hash[blacklist[i]] = last;
                ++last;
            }
        }
    }
    
    int pick() {
        int n = rand()%d_count;
        if (hash.find(n) != hash.end()) {
            return hash[n];
        }
        return n;
    }
    
private:
    int d_count;
    unordered_map<int, int> hash;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(N, blacklist);
 * int param_1 = obj->pick();
 */
