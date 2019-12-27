static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        for (int i = 0; i < arr.size();) {
            int l = i, r = arr.size()-1;
            while (l+1 < r) {
                int m = l+(r-l)/2;
                if (arr[m] == arr[i]) {
                    l = m;
                } else if (arr[m] > arr[i]) {
                    r = m-1;
                }
            }
            int t = r;   
            if (arr[r] != arr[i])  {
                t = l;
            }
            if (t-i+1 > arr.size()/4) {
                return arr[i];
            }
            i = t+1;
        }
        return -1;
    }
};
