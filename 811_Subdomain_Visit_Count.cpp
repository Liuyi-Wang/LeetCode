static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> counts;
        for (const auto& cp:cpdomains) {
            int index = cp.find(' ');
            string count = cp.substr(0, index);
            ++index;
            string domains = cp.substr(index);
            counts[domains] += atoi(count.c_str());
            index = 0;
            while (string::npos != (index = domains.find('.', index))) {
                ++index;
                counts[domains.substr(index)] += atoi(count.c_str());
            }
        }
        vector<string> result;
        for (unordered_map<string, int>::iterator it = counts.begin(); it != counts.end(); ++it) {
            result.push_back(to_string(it->second) + " " + it->first);
        }
        return result;
    }
};
