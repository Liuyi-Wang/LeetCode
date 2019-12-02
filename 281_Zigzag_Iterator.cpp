static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class ZigzagIterator {
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        if (v1.begin() != v1.end()) {
            q.push({v1.begin(), v1.end()});
        }
        if (v2.begin() != v2.end()) {
            q.push({v2.begin(), v2.end()});
        }
    }

    int next() {
        vector<int>::iterator it = q.front().first;
        vector<int>::iterator end = q.front().second;
        q.pop();
        int result = *it;
        ++it;
        if (it != end) {
            q.push({it, end});
        }
        return result;
    }

    bool hasNext() {
        return !q.empty();
    }
    
private:
    queue<pair<vector<int>::iterator, vector<int>::iterator>> q;
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */
