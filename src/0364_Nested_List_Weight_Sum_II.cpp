/**
 *  Time:
 *  O(n)
 *  Space:
 *  O(n)
 */
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
        vector<int> s;
        vector<int> d;
        int maxd;
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        maxd = 0;
        for (auto it:nestedList) {
            decode(it, 1);
        }
        int result = 0;
        for (int i = 0; i < s.size(); ++i) {
            result += (maxd-d[i]+1)*s[i];
        }
        return result;
    }
    
    void decode(NestedInteger it, int depth) {
        if (it.isInteger()) {
            s.push_back(it.getInteger());
            d.push_back(depth);
            maxd = max(maxd, depth);
            return;
        }
        for (auto next:it.getList()) {
            decode(next, depth+1);
        }
    }
};
