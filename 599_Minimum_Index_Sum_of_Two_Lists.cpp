static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> hash;
        for (int i = 0; i < list1.size(); ++i) {
            hash[list1[i]] = i;
        }
        vector<string> result;
        int sum = INT_MAX;
        for (int i = 0; i < list2.size(); ++i) {
            if (hash.find(list2[i]) == hash.end()) {
                continue;
            }
            if (sum > i+hash[list2[i]]) {
                result.clear();
                result.push_back(list2[i]);
                sum = i+hash[list2[i]];
            } else if (sum == i+hash[list2[i]]) {
                result.push_back(list2[i]);
            }
        }
        return result;
    }
};
