class Solution {
public:
    struct less_than {
        inline bool operator() (const int& i1,
                                const int& i2) {
            return abs(i1) < abs(i2);
        }    
    };
    
    bool canReorderDoubled(vector<int>& A) {
        if (A.size()%2) {
            return false;
        }
        sort(A.begin(), A.end(), less_than());
        unordered_map<int, int> m;
        int counts = 0;
        for (int i = A.size()-1; i >= 0; --i) {
            if (counts > i+1) {
                return false;
            }
            if (m[A[i]*2] > 0) {
                --m[A[i]*2];
                --counts;
            } else {
                ++m[A[i]];
                ++counts;
            }
        }
        return 0==counts;
    }
};
