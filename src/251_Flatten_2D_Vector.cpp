static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Vector2D {
public:
    Vector2D(vector<vector<int>>& v) {
        i = 0;
        for (int m = 0; m < v.size(); ++m) {
            for (int n = 0; n < v[m].size(); ++n) {
                d_v.push_back(v[m][n]);
            }
        }
    }
    
    int next() {
        return d_v[i++];
    }
    
    bool hasNext() {
        return i < d_v.size();
    }
    
private:
    vector<int> d_v;
    int i;
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(v);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
