/**
 *  Time:
 *  O(logn n logn)
 *  Space:
 *  O(n)
 */
class Solution {
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(tasks.begin(), tasks.end());
        int n = tasks.size();
        int m = workers.size();
        n = min(n, m);
        int l = 0, r = n;
        multiset<int> s(workers.begin(), workers.end());
        while (l < r) {
            int mid = l+(r-l)/2+1;
            if (isValid(tasks, mid, s, pills, strength)) {
                l = mid;
            } else {
                r = mid-1;
            }
        }
        return l;
    }
    
    bool isValid(const vector<int>& tasks, int n, multiset<int> s, int pills, int strength) {
        for (int i = n-1; i >= 0; --i) {
            multiset<int>::iterator it = s.end();
            --it;
            if (*it >= tasks[i]) {
                s.erase(it);
                continue;
            }
            if (pills == 0) {
                return false;
            }
            --pills;
            int target = tasks[i]-strength;
            it = s.lower_bound(target);
            if (it == s.end()) {
                return false;
            }
            s.erase(it);
        }
        return true;
    }
};
