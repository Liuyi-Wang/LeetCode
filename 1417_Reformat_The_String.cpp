class Solution {
public:
    string reformat(string s) {
        queue<char> dq, lq;
        for (auto c:s) {
            if (isdigit(c)) {
                dq.push(c);
            } else {
                lq.push(c);
            }
        }
        if (abs(static_cast<int>(lq.size())-static_cast<int>(dq.size())) > 1) {
            return "";
        }
        string result;
        if (lq.size() == dq.size()) {
            while (!lq.empty()) {
                result.push_back(dq.front());
                dq.pop();
                result.push_back(lq.front());
                lq.pop();
            }
        } else if (lq.size() > dq.size()) {
            result.push_back(lq.front());
            lq.pop();
            while (!lq.empty()) {
                result.push_back(dq.front());
                dq.pop();
                result.push_back(lq.front());
                lq.pop();
            }
        } else {
            result.push_back(dq.front());
            dq.pop();
            while (!dq.empty()) {
                result.push_back(lq.front());
                lq.pop();
                result.push_back(dq.front());
                dq.pop();
            }
        }
        return result;
    }
};
