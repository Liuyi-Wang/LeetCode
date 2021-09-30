class Solution {
public:
    int minKnightMoves(int x, int y) {
        vector<vector<int>> moves(601, vector<int>(601, -1));
        int offset = 300;
        moves[0+offset][0+offset] = 0;
        queue<pair<int, int>> q;
        q.push(pair<int, int>(0, 0));
        while (!q.empty()) {
            int X = q.front().first;
            int Y = q.front().second;
            int move = moves[X+offset][Y+offset];
            q.pop();
            if (X == x && Y == y) {
                return move;
            }
            if (X+1 <= 300 && Y+2 <= 300 && -1 == moves[X+1+offset][Y+2+offset]) {
                q.push(pair<int, int>(X+1, Y+2));
                moves[X+1+offset][Y+2+offset] = move+1;
            }
            if (X+2 <= 300 && Y+1 <= 300 && -1 == moves[X+2+offset][Y+1+offset]) {
                q.push(pair<int, int>(X+2, Y+1));
                moves[X+2+offset][Y+1+offset] = move+1;
            }
            if (X+2 <= 300 && Y-1 >= -300 && -1 == moves[X+2+offset][Y-1+offset]) {
                q.push(pair<int, int>(X+2, Y-1));
                moves[X+2+offset][Y-1+offset] = move+1;
            }
            if (X+1 <= 300 && Y-2 >= -300 && -1 == moves[X+1+offset][Y-2+offset]) {
                q.push(pair<int, int>(X+1, Y-2));
                moves[X+1+offset][Y-2+offset] = move+1;
            }
            if (X-1 >= -300 && Y-2 >= -300 && -1 == moves[X-1+offset][Y-2+offset]) {
                q.push(pair<int, int>(X-1, Y-2));
                moves[X-1+offset][Y-2+offset] = move+1;
            }
            if (X-2 >= -300 && Y-1 >= -300 && -1 == moves[X-2+offset][Y-1+offset]) {
                q.push(pair<int, int>(X-2, Y-1));
                moves[X-2+offset][Y-1+offset] = move+1;
            }
            if (X-2 >= -300 && Y+1 <= 300 && -1 == moves[X-2+offset][Y+1+offset]) {
                q.push(pair<int, int>(X-2, Y+1));
                moves[X-2+offset][Y+1+offset] = move+1;
            }
            if (X-1 >= -300 && Y+2 <= 300 && -1 == moves[X-1+offset][Y+2+offset]) {
                q.push(pair<int, int>(X-1, Y+2));
                moves[X-1+offset][Y+2+offset] = move+1;
            }
        }
        return 0;
    }
};
