static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        vector<int> sums = nums;
        for (int i = 1; i < sums.size(); ++i) {
            sums[i] = sums[i]+sums[i-1];
        }
        vector<int> l(nums.size(), 0);
        for (int i = k; i < l.size()-2*k; ++i) {
            int index = l[i-1];
            int sum = sums[index+k-1];
            if (index > 0) {
                sum -= sums[index-1];
            }
            if (sum < sums[i]-sums[i-k]) {
                l[i] = i-k+1;
            } else {
                l[i] = index;
            }
        }
        vector<int> r(nums.size(), nums.size()-k);
        for (int i = r.size()-k-1; i >= 2*k; --i) {
            int index = r[i+1];
            int sum = sums[index+k-1]-sums[index-1];
            if (sum <= sums[i+k-1]-sums[i-1]) {
                r[i] = i;
            } else {
                r[i] = index;
            }
        }
        vector<int> result(3, 0);
        int maxSum = 0;
        for (int i = k; i <= sums.size()-2*k; ++i) {
            int li = l[i-1];
            int sum = sums[li+k-1];
            if (li > 0) {
                sum -= sums[li-1];
            }
            int ri = r[i+k];
            sum += (sums[i+k-1]-sums[i-1])+(sums[ri+k-1]-sums[ri-1]);
            if (sum > maxSum) {
                result[0] = li;
                result[1] = i;
                result[2] = ri;
                maxSum = sum;
            }
        }
        return result;
    }
};
