static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    string simplifyPath(string path) {
        stack<string> s;
        int begin = 0;
        int next;
        while (string::npos != (next = path.find("/", begin+1))) {
            string p = path.substr(begin+1, next-1-begin);
            if (".." == p && !s.empty()) {
                s.pop();
            } else if (0 != p.size() && "." != p && ".." != p) {
                s.push(p);
            }
            begin = next;
        }
        if (path.back() != '/') {
            string p = path.substr(begin+1, path.size()-1-begin);
            if (".." == p && !s.empty()) {
                s.pop();
            } else if (0 != p.size() && "." != p && ".." != p) {
                s.push(p);
            }
        }
        if (s.empty()) {
            return "/";
        }
        string result;
        while (!s.empty()) {
            result = "/"+s.top()+result;
            s.pop();
        }
        return result;
    }
};
