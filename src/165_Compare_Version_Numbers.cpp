static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int solve(const string &version, int &i) {
        if (i >= version.size()) {
            return 0;
        }
        int j = version.find(".", i);
        if (string::npos == j) {
            int t = i;
            i = version.size();
            return atoi(version.substr(t, version.size()-t).c_str());
        } else {
            int t = i;
            i = j+1;
            return atoi(version.substr(t, j-t).c_str());
        }
    }
    
    int compareVersion(string version1, string version2) {
        int i1 = 0, i2 = 0;
        while (i1 < version1.size() || i2 < version2.size()) {
            int v1 = solve(version1, i1);
            int v2 = solve(version2, i2);
            if (v1 > v2) {
                return 1;
            }
            if (v1 < v2) {
                return -1;
            }
        }
        return 0;
    }
};
