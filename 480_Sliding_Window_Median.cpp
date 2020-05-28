class Solution {
public:
    void push(int num, multiset<int>& max_q, multiset<int>& min_q) {
        if (max_q.empty() && min_q.empty()) {
            max_q.insert(num);
            return;
        }
        if (!max_q.empty()) {
            if (*max_q.rbegin() <= num) {
                min_q.insert(num);
            } else {
                max_q.insert(num);
            }
        } else {
            if (*min_q.begin() >= num) {
                max_q.insert(num);
            } else {
                min_q.insert(num);
            }
        }
        while (max_q.size() < min_q.size()) {
            max_q.insert(*min_q.begin());
            min_q.erase(min_q.begin());
        }
        while (max_q.size() > min_q.size()+1) {
            min_q.insert(*max_q.rbegin());
            max_q.erase(--max_q.end());
        }
    }
    
    void pop(int num, multiset<int>& max_q, multiset<int>& min_q) {
        if (max_q.find(num) != max_q.end()) {
            max_q.erase(max_q.find(num));
        } else {
            min_q.erase(min_q.find(num));
        }
    }
    
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<int> max_q, min_q;
        int i = 0;
        for (; i < k; ++i) {
            push(nums[i], max_q, min_q);
        }
        vector<double> result;
        if (k%2 == 1) {
            result.push_back(*max_q.rbegin());
        } else {
            result.push_back((double(*max_q.rbegin())+double(*min_q.begin()))/2);
        }
        for (; i < nums.size(); ++i) {
            pop(nums[i-k], max_q, min_q);
            push(nums[i], max_q, min_q);
            if (k%2 == 1) {
                result.push_back(*max_q.rbegin());
            } else {
                result.push_back((double(*max_q.rbegin())+double(*min_q.begin()))/2);
            }
        }
        return result;
    }
};
