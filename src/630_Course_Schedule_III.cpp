static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    struct less_than {
        inline bool operator() (const vector<int> &v1,
                                const vector<int> &v2) {
            return v1[1] < v2[1];
        }    
    };
    
    int scheduleCourse(vector<vector<int>>& courses) {
        int result = 0;
        int sum = 0;
        sort(courses.begin(), courses.end(), less_than());
        priority_queue<int> q;
        for (auto c:courses) {
            sum += c[0];
            q.push(c[0]);
            if (sum > c[1]) {
                sum -= q.top();
                q.pop();
            } else {
                ++result;
            }
        }
        return result;
    }
};
