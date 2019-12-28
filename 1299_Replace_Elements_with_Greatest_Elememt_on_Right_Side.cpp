static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int last = arr.back();
        for (int i = arr.size()-2; i >= 0; --i) {
            int t = arr[i];
            arr[i] = last;
            last = max(last, t);
        }
        arr.back() = -1;
        return arr;
    }
};
