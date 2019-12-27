static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> result;
        int diff = INT_MAX;
        for (int i = 1; i < arr.size(); ++i) {
            if (arr[i]-arr[i-1] < diff) {
                result.clear();
                vector<int> v;
                v.push_back(arr[i-1]);
                v.push_back(arr[i]);
                result.push_back(v);
                diff = arr[i]-arr[i-1];
            } else if (arr[i]-arr[i-1] == diff) {
                vector<int> v;
                v.push_back(arr[i-1]);
                v.push_back(arr[i]);
                result.push_back(v);
            }
        }
        return result;
    }
};
