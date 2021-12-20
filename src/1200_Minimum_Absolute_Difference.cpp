class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        map<int, vector<vector<int>>> hash;
        int diff = INT_MAX;
        for (int i = 1; i < arr.size(); ++i) {
            diff = min(diff, arr[i]-arr[i-1]);
            hash[arr[i]-arr[i-1]].push_back({arr[i-1], arr[i]});
        }
        return hash[diff];
    }
};
