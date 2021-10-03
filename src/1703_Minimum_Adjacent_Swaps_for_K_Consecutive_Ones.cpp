class Solution {
public:
    int minMoves(vector<int>& nums, int k) {
        if ( k == 1) {
            return 0;
        }
        vector<int> ones;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 1) {
                ones.push_back(i);
            }
        }
        int result = INT_MAX;
        int l = 0, r = k-1;
        int mid = l+(r-l)/2;
        int sum = 0;
        for (int i = l; i <= r; ++i) {
            sum += abs(ones[i]-ones[mid]);
        }
        ++l;
        ++r;
        result = min(result, sum);
        while (r < ones.size()) {
            mid = l+(r-l)/2;
            /// deduct left end
            sum -= (ones[mid-1]-ones[l-1]);
            /// add right end
            sum += (ones[r]-ones[mid]);
            /// if k is odd, k-1 is even
            if (k%2 == 0) {
                sum -= (ones[mid]-ones[mid-1]);
            }
            result = min(result, sum);
            ++l;
            ++r;
        }
        if (k%2 == 1) {
            result -= (1+k/2)*(k/2);
        } else {
            result -= (1+k/2-1)*(k/2-1)/2; 
            result -= (1+k/2)*(k/2)/2;
        }
        return result;
    }
};
