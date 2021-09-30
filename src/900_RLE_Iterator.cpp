class RLEIterator {
public:
    RLEIterator(vector<int>& A) {
        for (int i = 0; i < A.size(); i += 2) {
            if (0 != A[i]) {
                d_c.push_back(A[i]);
                d_v.push_back(A[i+1]);
            }
        }
        d_i = 0;
    }
    
    int next(int n) {
        int result = -1;
        for (; d_i < d_c.size(); ++d_i) {
            if (d_c[d_i] < n) {
                n -= d_c[d_i];
                continue;
            }
            result = d_v[d_i];
            if (d_c[d_i] == n) {
                ++d_i;
            } else {
                d_c[d_i] -= n;
            } 
            break;
        }
        return result;
    }
private:
    vector<int> d_c;
    vector<int> d_v;
    int d_i;
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(A);
 * int param_1 = obj->next(n);
 */
