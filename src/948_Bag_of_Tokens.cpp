class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
        if (1 == tokens.size()) {
            return tokens[0]<=P;
        }
        int begin = 0, end = tokens.size()-1;
        sort(tokens.begin(), tokens.end());
        int point = 0;
        int result = 0;
        while (begin < end) {
            if (tokens[begin] > P) {
                if (0 == point) {
                    break;
                }
                --point;
                P += tokens[end--];
            } else {
                while (tokens[begin] <= P) {
                    P -= tokens[begin++];
                    ++point;
                }
                result = max(result, point);
            }
        }
        return result;
    }
};
