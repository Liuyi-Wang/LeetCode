static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<int> partitionLabels(string S) {
        unordered_map<char, int> hash;
        for (int i = 0; i < S.size(); ++i) {
            hash[S[i]] = i;
        }
        int begin = 0, end = 0;
        vector<int> result;
        while(end < S.size()) {
            for (int i = begin; i <= end; ++i) {
                end = max(end, hash[S[i]]);
            }
            result.push_back(end-begin+1);
            ++end;
            begin = end;
        }
        return result;
    }
};
