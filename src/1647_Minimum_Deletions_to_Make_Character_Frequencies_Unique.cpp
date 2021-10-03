class Solution {
public:
    int minDeletions(string s) {
        vector<int> v(26, 0);
        for (auto c:s) {
            ++v[c-'a'];
        }
        sort(v.begin(), v.end());
        int last = v.back();
        int result = 0;
        for (int i = static_cast<int>(v.size())-2; i >= 0; --i) {
            if (v[i] == 0) {
                break;
            }
            if (last == 0) {
                result += v[i];
            } else if (v[i] >= last) {
                result += (v[i]-last+1);
                last = last-1;
            } else {
                last = v[i];
            }
        }
        return result;
    }
};
