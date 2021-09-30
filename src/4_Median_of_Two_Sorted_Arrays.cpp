class Solution {
public:
    double findK(vector<int>& nums1, int b1, int e1, 
                 vector<int>& nums2, int b2, int e2,
                 int K) {
        int l1 = e1-b1+1;
        int l2 = e2-b2+1;
        if (l1 < l2) {
            return findK(nums2, b2, e2, nums1, b1, e1, K);
        }
        if (0 == l2) {
            return nums1[b1+K-1];
        }
        if (1 == K) {
            return min(nums1[b1], nums2[b2]);
        }
        int l = min(K/2, l2);
        if (nums1[b1+l-1] < nums2[b2+l-1]) {
            return findK(nums1, b1+l, e1, nums2, b2, e2, K-l);
        } else {
            return findK(nums1, b1, e1, nums2, b2+l, e2, K-l);
        }
    }
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len = nums1.size()+nums2.size();
        if (0 == len%2) {
            return (findK(nums1, 0, nums1.size()-1, nums2, 0, nums2.size()-1, len/2)+
                    findK(nums1, 0, nums1.size()-1, nums2, 0, nums2.size()-1, len/2+1))/2;
        } else {
            return findK(nums1, 0, nums1.size()-1, nums2, 0, nums2.size()-1, len/2+1);
        }
    }
};
