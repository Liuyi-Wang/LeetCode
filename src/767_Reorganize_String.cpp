class Solution {
public:
    string reorganizeString(string S) {
        vector<int> counts(26, 0);
        for (int i = 0; i < S.size(); ++i) {
            ++counts[S[i]-'a'];
        }
        priority_queue<pair<int, char>> q;
        for (int i = 0; i < counts.size(); ++i) {
            q.push({counts[i], 'a'+i});
        }
        if (q.top().first > (S.size()+1)/2) {
            return "";
        }
        string result = S;
        int i = 0;
        while (!q.empty()) {
            int count = q.top().first;
            char c = q.top().second;
            q.pop();
            while (i < result.size() && count > 0) {
                result[i] = c;
                i += 2;
                --count;
            }
            if (count > 0) {
                i = 1;
                while (i < result.size() && count > 0) {
                    result[i] = c;
                    i += 2;
                    --count;
                }
            }
        }
        return result;
    }
};
