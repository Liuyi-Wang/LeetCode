static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> v(rooms.size(), false);
        v[0] = true;
        int count = 1;
        queue<int> q;
        q.push(0);
        while (!q.empty()) {
            int r = q.front();
            q.pop();
            for (auto room:rooms[r]) {
                if (v[room]) {
                    continue;
                }
                v[room] = true;
                ++count;
                q.push(room);
            }
        }
        return count == rooms.size();
    }
};
