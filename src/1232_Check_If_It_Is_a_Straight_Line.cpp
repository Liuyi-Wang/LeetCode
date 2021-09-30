static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}(); 

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        if (2 == coordinates.size()) {
            return true;
        }
        if (coordinates[0][0] == coordinates[1][0]) {
            for (int i = 2; i < coordinates.size(); ++i) {
                if (coordinates[0][0] != coordinates[i][0]) {
                    return false;
                }
            }
            return true;
        }
        if (coordinates[0][1] == coordinates[1][1]) {
            for (int i = 2; i < coordinates.size(); ++i) {
                if (coordinates[0][1] != coordinates[i][1]) {
                    return false;
                }
            }
            return true;
        }
        double slop = double(coordinates[1][1]-coordinates[0][1])/(coordinates[1][0]-coordinates[0][0]);
        for (int i = 2; i < coordinates.size(); ++i) {
            if (slop != double(coordinates[i][1]-coordinates[0][1])/(coordinates[i][0]-coordinates[0][0])) {
                return false;
            }
        }
        return true;
    }
};
