static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    void solve(const vector<string> &words, int begin, int end, int i) {
        for (; begin <= end; ++begin) {
            if (words[begin].size() > i) {
                break;
            }
        }
        if (begin >= end) {
            return;
        }
        int last = begin;
        ++begin;
        while (begin <= end) {
            if (words[begin][i] != words[last][i]) {
                solve(words, last, begin-1, i+1);
                if (d_hash[words[last][i]].find(words[begin][i]) == d_hash[words[last][i]].end()) {
                    d_hash[words[last][i]].insert(words[begin][i]);
                    ++d_c[words[begin][i]];
                }
                last = begin;
            }
            ++begin;
        }
        solve(words, last, begin-1, i+1);
    }
    
    string alienOrder(vector<string>& words) {
        for (auto w:words) {
            for (auto c:w) {
                d_s.insert(c);
            }
        }
        solve(words, 0, words.size()-1, 0);
        queue<char> q;
        string result;
        for (unordered_set<char>::iterator it = d_s.begin(); it != d_s.end(); ++it) {
            if (d_c.find(*it) == d_c.end()) {
                q.push(*it);
                result += *it;
            }
        }
        while (!q.empty()) {
            char c = q.front();
            q.pop();
            for (auto i:d_hash[c]) {
                --d_c[i];
                if (0 == d_c[i]) {
                    q.push(i);
                    result += i;
                }
            }
        }
        for (auto i:d_c) {
            if (0 != i.second) {
                return "";
            }
        }
        return result;
    }
    
private:
    unordered_map<char, set<char>> d_hash;
    unordered_set<char> d_s;
    unordered_map<char, int> d_c;
};
