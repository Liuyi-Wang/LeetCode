/**
 *  Time:
 *  O(n)
 *  Space:
 *  O(n)
 */
class Solution {
    vector<int> d_r;
public:
    int find(int a) {
        int r = a;
        while (d_r[r] != r) {
            r = d_r[r];
        }
        while (d_r[a] != r) {
            int t = d_r[a];
            d_r[a] = r;
            a = t;
        }
        return r;
    }
    
    void merge(int a, int b) {
        int ra = find(a);
        int rb = find(b);
        if (ra < rb) {
            d_r[rb] = ra;
        } else {
            d_r[ra] = rb;
        }
    }
    
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        d_r = vector<int>(n, 0);
        for (int i = 1; i < n; ++i) {
            d_r[i] = i;
        }
        d_r[firstPerson] = 0;
        
        unordered_set<int> result;
        result.insert(0);
        result.insert(firstPerson);
        
        auto cmp = [](const vector<int>& v1, const vector<int>& v2) {
            return v1.back() < v2.back();
        };
        sort(meetings.begin(), meetings.end(), cmp);
        
        for (int i = 0; i < meetings.size();) {
            int j = i;
            unordered_set<int> visited;
            for (; j < meetings.size() && meetings[j].back() == meetings[i].back(); ++j) {
                merge(meetings[j][0], meetings[j][1]);
                visited.insert(meetings[j][0]);
                visited.insert(meetings[j][1]);
            }
            for (auto person:visited) {
                if (find(person) != 0) {
                    d_r[person] = person;
                } else {
                    result.insert(person);
                }
            }
            i = j;
        }
        return vector<int>(result.begin(), result.end());
    }
};
