class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> result;
        int num = 1;
        for (int i = 0; i < target.size(); ++i) {
            if (num == target[i]) {
                ++num;
                result.push_back("Push");
            } else {
                while (num != target[i]) {
                    result.push_back("Push");
                    result.push_back("Pop");
                    ++num;
                }
                ++num;
                result.push_back("Push");
            }
        }
        return result;
    }
};
