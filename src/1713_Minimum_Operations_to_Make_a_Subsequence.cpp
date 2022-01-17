/**
 *  Time:
 *  O(nlogn)
 *  Space:
 *  O(n)
 */
class Solution {
    unordered_map<int, int> hash;
public:
    int minOperations(vector<int>& target, vector<int>& arr) {
        for (int i = 0; i < target.size(); ++i) {
            hash[target[i]] = i;
        }
        int n = arr.size();
        vector<int> index;
        for (auto a:arr) {
            if (hash.find(a) != hash.end()) {
                index.push_back(hash[a]);
            }
        }
        if (index.empty()) {
            return target.size();
        }
        vector<int> result = {index[0]};
        for (int i = 1; i < index.size(); ++i) {
            if (result.back() < index[i]) {
                result.push_back(index[i]);
            } else {
                vector<int>::iterator it = lower_bound(result.begin(), result.end(), index[i]);
                *it = index[i];
            }
        }
        return target.size()-result.size();
    }
};
