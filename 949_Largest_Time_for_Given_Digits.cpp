static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    void solve(vector<int>& nums, int i) {
        if (i == nums.size()-1) {
            if (nums[0]*10+nums[1] > 23) {
                return;
            }
            if (nums[2]*10+nums[3] > 59) {
                return;
            }
            d_result = max(d_result, nums[0]*1000+nums[1]*100+nums[2]*10+nums[3]);
            return;
        }
        for (int j = i; j < nums.size(); ++j) {
            swap(nums[i], nums[j]);
            solve(nums, i+1);
            swap(nums[i], nums[j]);
        }
    }
    
    string largestTimeFromDigits(vector<int>& A) {
        d_result = -1;
        solve(A, 0);
        string result;
        if (-1 == d_result) {
            return result;   
        }
        result += to_string(d_result/1000);
        d_result %= 1000;
        result += to_string(d_result/100);
        d_result %= 100;
        result += ":";
        result += to_string(d_result/10);
        d_result %= 10;
        result += to_string(d_result);
        return result;
    }

private:
    int d_result;
};
