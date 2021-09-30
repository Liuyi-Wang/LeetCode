static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
    int solve(int id) {
        int result = 0;
        for (auto s:d_info[id]->subordinates) {
            result += solve(s);
        }
        return result+d_info[id]->importance;
    }
    
    int getImportance(vector<Employee*> employees, int id) {
        for (auto e:employees) {
            d_info[e->id] = e;
        }
        return solve(id);
    }
    
private:
    unordered_map<int, Employee*> d_info;
};
