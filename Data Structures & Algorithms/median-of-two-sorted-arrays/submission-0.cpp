class Solution {
private:
    double getKth(vector<int>& a, int aSize, int aStart, vector<int>& b, int bSize, int bStart, int k) {
        if (aSize > bSize) return getKth(b, bSize, bStart, a, aSize, aStart, k);
        if (aSize == 0) return b[bStart + k - 1];
        if (k == 1) return min(a[aStart], b[bStart]);

        int i = min(aSize, k/2);
        int j = min(bSize, k/2);

        if (a[aStart + i - 1] > b[bStart + j - 1]){
            return getKth(a, aSize, aStart, b, bSize - j, bStart + j, k - j);
        }
        else {
            return getKth(a, aSize - i, aStart + i, b, bSize, bStart, k - i);
        }

    }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int left = (nums1.size() + nums2.size() + 1) / 2;
        int right = (nums1.size() + nums2.size() + 2) / 2;
        return (getKth(nums1, nums1.size(), 0, nums2, nums2.size(), 0, left) +
        getKth(nums1, nums1.size(), 0, nums2, nums2.size(), 0, right)) / 2.0;
    }
};
