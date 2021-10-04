class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<int> pq(target.begin(), target.end());
        long sum = accumulate(target.begin(), target.end(), 0LL);
        while(true){
            int top = pq.top();
            pq.pop();
            sum -= top;
            if(top == 1 || sum == 1){ return true; }
            if(sum == 0 || sum > top || top % sum == 0){ return false; };
            top %= sum;
            sum += top;
            pq.push(top);
        }
        return false;
    }
};
