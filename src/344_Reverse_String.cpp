class Solution {
public:
    void reverseString(vector<char>& s) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        
        int begin = 0, end = s.size()-1;
        while (begin < end) {
            swap(s[begin++], s[end--]);
        }
    }
};
