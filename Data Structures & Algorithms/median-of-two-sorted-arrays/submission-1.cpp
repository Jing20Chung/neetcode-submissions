class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);
        int size1 = nums1.size();
        int size2 = nums2.size();
        int totalN = size1 + size2;
        int halfN = (totalN + 1) / 2;
        
        int l = 0, r = size1;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            int midB = halfN - mid;

            int lA = mid > 0? nums1[mid - 1]: INT_MIN;
            int rA = mid < size1? nums1[mid]: INT_MAX;

            int lB = midB > 0? nums2[midB - 1]: INT_MIN;
            int rB = midB < size2? nums2[midB]: INT_MAX;

            if (lA <= rB && lB <= rA) {
                if (totalN % 2 == 0) {
                    return (max(lA, lB) + min(rA, rB))/ 2.0;
                }
                else {
                    return max(lA, lB);
                }
            }
            else if (lA > rB) {
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return -1;
    }
};
