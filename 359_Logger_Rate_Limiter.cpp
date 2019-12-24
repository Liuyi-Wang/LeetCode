class Logger {
public:
    /** Initialize your data structure here. */
    Logger() {
        
    }
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        if (d_hash.find(message) == d_hash.end()) {
            d_hash[message] = timestamp;
            return true;
        }
        if (timestamp-d_hash[message] < 10) {
            return false;
        }
        d_hash[message] = timestamp;
        return true;
    }
    
private:
    unordered_map<string, int> d_hash;
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */
