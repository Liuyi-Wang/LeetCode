static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        int sa = 0;
        for (auto a:A) {
            sa += a;
        }
        int sb = 0;
        for (auto b:B) {
            sb += b;
        }
        int avg = (sa+sb)/2;
        bool ab = false;
        if (sa > avg) {
            vector<int> t = A;
            A = B;
            B = t;
            int st = sa;
            sa = sb;
            sb = st;
            ab = true;
        }
        int diff = avg-sa;
        int ia = 0, ib = 0;
        vector<int> result;
        for (; ia < A.size(); ++ia) {
            for (; ib < B.size(); ++ib) {
                if (B[ib]-A[ia] == diff) {
                    if (ab) {
                        result.push_back(B[ib]);
                        result.push_back(A[ia]);
                    } else {
                        result.push_back(A[ia]);
                        result.push_back(B[ib]);
                    }
                    return result;
                }
                if (B[ib]-A[ia] > diff) {
                    break;
                }
            }
        }
        return result;
    }
};
