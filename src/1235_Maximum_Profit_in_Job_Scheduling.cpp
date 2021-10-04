class Solution {
public:
    struct less_than {
        inline bool operator() (const vector<int>& v1, const vector<int>& v2) {
            return v1[1] < v2[1];
        }    
    };
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> jobs;
        for (int i = 0; i < startTime.size(); ++i) {
            vector<int> job;
            job.push_back(startTime[i]);
            job.push_back(endTime[i]);
            job.push_back(profit[i]);
            jobs.push_back(job);
        }
        sort(jobs.begin(), jobs.end(), less_than());
        vector<int> dp(jobs.size(), 0);
        dp[0] = jobs[0][2];
        for (int i = 1; i < jobs.size(); ++i) {
            int j = findJ(jobs, i);
            dp[i] = dp[i-1];
            if (-1 != j) {
                dp[i] = max(dp[i], dp[j]+jobs[i][2]);
            } else {
                dp[i] = max(dp[i], jobs[i][2]);
            }
        }
        return dp.back();
    }
    
    int findJ(const vector<vector<int>>& jobs, int i) {
        int target = jobs[i][0];
        // find index <= target
        int begin = 0, end = i-1;
        while (begin+1 < end) {
            int mid = begin+(end-begin)/2;
            if (jobs[mid][1] == target) {
                begin = mid;
            } else if (jobs[mid][1] < target) {
                begin = mid;
            } else {
                end = mid-1;
            }
        }
        if (jobs[end][1] <= target) {
            return end;
        }
        if (jobs[begin][1] <= target) {
            return begin;
        }
        return -1;
    }
};
