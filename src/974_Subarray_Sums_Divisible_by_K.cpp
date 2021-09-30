static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        vector<int> sum(A.size()+1, 0);
        unordered_map<int, int> hash;
        hash[0] = 1;
        int result = 0;
        for (int i = 1; i < sum.size(); ++i) {
            sum[i] = sum[i-1]+A[i-1];
            int k = (sum[i]%K+K)%K;
            if (hash.find(k) != hash.end()) {
                result += hash[k];
            }
            ++hash[k];
        }
        return result;
    }
};
