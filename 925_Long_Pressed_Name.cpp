class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int ni = 0, ti = 0;
        while (ni < name.size() && ti < typed.size()) {
            int i = ni+1;
            while (i < name.size()) {
                if (name[ni] == name[i]) {
                    ++i;
                } else {
                    break;
                }
            }
            int j = ti;
            for (; j < ti+i-ni; ++j) {
                if (name[ni] != typed[j]) {
                    return false;
                }
            }
            while (j < typed.size()) {
                if (name[ni] == typed[j]) {
                    ++j;
                } else {
                    break;
                }
            }
            ni = i;
            ti = j;
        }
        return (ni == name.size() && ti == typed.size());
    }
};
