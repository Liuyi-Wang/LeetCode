static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
        vector<int> result;
        int i1 = 0, i2 = 0, i3 = 0;
        while (i1 < arr1.size() && i2 < arr2.size() && i3 < arr3.size()) {
            if (arr1[i1] == arr2[i2] && arr1[i1] == arr3[i3]) {
                result.push_back(arr1[i1]);
                ++i1;
                ++i2;
                ++i3;
                continue;
            }
            int m = max(max(arr1[i1], arr2[i2]), arr3[i3]);
            if (arr1[i1] < m) {
                ++i1;
            }
            if (arr2[i2] < m) {
                ++i2;
            }
            if (arr3[i3] < m) {
                ++i3;
            }
        }
        return result;
    }
};
