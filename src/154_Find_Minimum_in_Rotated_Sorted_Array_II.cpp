class Solution {
public:
    int findMin(vector<int>& nums) {
        return binarySearch(nums, 0, nums.size()-1);
    }
    
    int binarySearch(const vector<int>& nums, int begin, int end) {
        if (begin == end) {
            return nums[begin];
        }
        int mid = begin+(end-begin)/2;
        if (nums[begin] < nums[mid] && nums[mid] < nums[end]) {
            return nums[begin];
        }
        if (nums[begin] > nums[mid] && nums[mid] > nums[end]) {
            return nums[end];
        }
        if (nums[begin] < nums[mid] && nums[mid] > nums[end]) {
            return binarySearch(nums, mid+1, end);
        }
        if (nums[begin] > nums[mid] && nums[mid] < nums[end]) {
            return binarySearch(nums, begin+1, mid);
        }
        if (nums[begin] == nums[mid] && nums[mid] < nums[end]) {
            return nums[mid];
        }
        if (nums[begin] == nums[mid] && nums[mid] > nums[end]) {
            return binarySearch(nums, mid+1, end);
        }
        if (nums[begin] < nums[mid] && nums[mid] == nums[end]) {
            return nums[begin];
        }
        if (nums[begin] > nums[mid] && nums[mid] == nums[end]) {
            return binarySearch(nums, begin+1, mid);
        }
        int result = INT_MAX;
        for (int i = begin; i <= end; ++i) {
            result = min(result, nums[i]);
        }
        return result;
    }
};
