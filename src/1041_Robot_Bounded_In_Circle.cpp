class Solution {
public:
    bool isRobotBounded(string instructions) {
        vector<int> pos = {0, 0};
        int face = 0;
        vector<int> dx = {0, 1, 0, -1};
        vector<int> dy = {-1, 0, 1, 0};
        for (auto instruction:instructions) {
            if (instruction == 'G') {
                pos[0] += dx[face];
                pos[1] += dy[face];
            } else if (instruction == 'L') {
                face = (face-1+4)%4;
            } else if (instruction == 'R') {
                face = (face+1)%4;
            }
        }
        return (pos[0] == 0 && pos[1] == 0) || face != 0;
    }
};
