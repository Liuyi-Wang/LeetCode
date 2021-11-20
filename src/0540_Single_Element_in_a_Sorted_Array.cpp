/**
 *  Time:
 *  O(logn)
 *  Space:
 *  O(1)
 */
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        return binarySearch(nums, 0, nums.size()-1);
    }
    
    int binarySearch(const vector<int>& nums, int l, int r){
        if (l == r) {
            return nums[l];
        }
        int mid = l+(r-l)/2;
        if (mid == 0) {
            if (nums[mid] == nums[mid+1]) {
                return binarySearch(nums, mid+2, r);
            } else {
                return nums[mid];
            }
        } else if (mid == nums.size()-1) {
            if (nums[mid] == nums[mid-1]) {
                return binarySearch(nums, l, mid-2);
            } else {
                return nums[mid];
            }
        } else {
            if (nums[mid] == nums[mid-1]) {
                if ((mid-2-l+1)%2 == 1) {
                    return binarySearch(nums, l, mid-2);
                } else {
                    return binarySearch(nums, mid+1, r);
                }
            } else if (nums[mid] == nums[mid+1]) {
                if ((mid-1-l+1)%2 == 1) {
                    return binarySearch(nums, l, mid-1);
                } else {
                    return binarySearch(nums, mid+2, r);
                }
            } else {
                return nums[mid];
            }
        }
        return nums[l];
    }
};
