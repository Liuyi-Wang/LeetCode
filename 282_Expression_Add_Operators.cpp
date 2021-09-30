class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> results;
        for (int i = 0; i < num.size(); ++i) {
            string curNum = num.substr(0, i+1);
            if (curNum[0] == '0' && curNum.size() > 1) {
                continue;
            }
            long long curValue = stoll(curNum);
            dfs(num, i+1, target, curNum, curValue, curValue, results);
        }
        return results;
    }
    
    void dfs(const string& num, int i, int target, string result, long long value, long long lastValue, vector<string>& results) {
        if (i == num.size()) {
            if (value == target) {
                results.push_back(result);
            }
            return;
        }
        for (int j = i; j < num.size(); ++j) {
            string curNum = num.substr(i, j-i+1);
            if (curNum[0] == '0' && curNum.size() > 1) {
                break;
            }
            long long curValue = stoll(curNum);
            dfs(num, j+1, target, result+"+"+curNum, value+curValue, curValue, results);
            dfs(num, j+1, target, result+"-"+curNum, value-curValue, -curValue, results);
            dfs(num, j+1, target, result+"*"+curNum, (value-lastValue)+lastValue*curValue, lastValue*curValue, results);
        }
    }
};
