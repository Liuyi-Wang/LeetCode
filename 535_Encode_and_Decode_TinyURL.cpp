static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    Solution() {
        dict = "0123456789qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";
    }

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if (ltos.find(longUrl) != ltos.end()) {
            return "http://tinyurl.com/"+ltos[longUrl];
        }
        string shortUrl;
        for (int i = 0; i < 6; ++i) {
            shortUrl += dict[rand()%62];
        }
        unsigned int i = 0;
        while (stol.find(shortUrl) != stol.end()) {
            shortUrl[i%6] = dict[rand()%62];
            ++i;
        }
        stol[shortUrl] = longUrl;
        ltos[longUrl] = shortUrl;
        return "http://tinyurl.com/"+shortUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        int i = shortUrl.find_last_of('/');
        return stol[shortUrl.substr(i+1)];
    }
    
private:
    string dict;
    unordered_map<string, string> stol;
    unordered_map<string, string> ltos;
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
