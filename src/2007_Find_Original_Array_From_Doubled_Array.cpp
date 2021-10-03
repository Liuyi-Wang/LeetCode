class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        if (changed.size()%2 == 1) {
            return {};
        }
        vector<int> result;
        multiset<int> s(changed.begin(), changed.end());
        for (multiset<int>::iterator it = s.begin(); it != s.end();) {
            multiset<int>::iterator cur = it;
            ++it;
            int original = *cur;
            s.erase(cur);
            int target = original*2;
            multiset<int>::iterator tit = s.end();
            if (*it == target) {
                cur = it;
                ++it;
                s.erase(cur);
                result.push_back(original);
            } else {
                tit = s.find(target);
                if (tit == s.end()) {
                    return {};
                }
                s.erase(tit);
                result.push_back(original);
            }
        }
        return result;
    }
};
