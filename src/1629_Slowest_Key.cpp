class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        char c = keysPressed[0];
        int time = releaseTimes[0];
        for (int i = 1; i < releaseTimes.size(); ++i) {
            if (releaseTimes[i]-releaseTimes[i-1] > time) {
                c = keysPressed[i];
                time = releaseTimes[i]-releaseTimes[i-1];
            } else if (releaseTimes[i]-releaseTimes[i-1] == time) {
                c = max(c, keysPressed[i]);
            }
        }
        return c;
    }
};
