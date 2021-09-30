class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> s;
        for (const auto email:emails) {
            string e;
            for (int i = 0; i < email.size();) {
                if ('.' == email[i]) {
                    ++i;
                    continue;    
                }
                if ('+' == email[i]) {
                    ++i;
                    while ('@' != email[i]) {
                        ++i;
                    }
                    e += email.substr(i, email.size()-i);
                    break;
                }
                if ('@' == email[i]) {
                    e += email.substr(i, email.size()-i);
                    break;
                }
                e += email[i++];
            }
            s.insert(e);
        }
        return s.size();
    }
};
