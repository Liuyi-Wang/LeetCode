static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for (const auto &e:nestedList) {
            if (e.isInteger()) {
                d_q.push(e.getInteger());
            } else {
                NestedIterator it = NestedIterator(const_cast<vector<NestedInteger> &>(e.getList()));
                while (it.hasNext()) {
                    d_q.push(it.next());
                }
            }
        }
    }

    int next() {
        int result = d_q.front();
        d_q.pop();
        return result;
    }

    bool hasNext() {
        return !d_q.empty();
    }
    
private:
    queue<int> d_q;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
