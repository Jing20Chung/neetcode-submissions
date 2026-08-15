/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        // this sounds like binary search variant
        int len = mountainArr.length();
        int peak = findPeak(mountainArr, len);
        if (peak == -1) return -1;
        int leftResult = search(0, peak, target, mountainArr, true);
        if (leftResult != -1) return leftResult;

        return search(peak + 1, len - 1, target, mountainArr, false);
    }

    int findPeak(MountainArray& mArr, int len) {
        int l = 1, r = len - 2;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            int midVal = mArr.get(mid);
            int prevVal = mArr.get(mid - 1);
            int nextVal = mArr.get(mid + 1);

            if (midVal > prevVal && midVal > nextVal) return mid;
            else if (midVal > prevVal && midVal < nextVal) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        return -1;
    }

    int search(int l, int r, int target, MountainArray& mArr, bool acend) {
        while (l <= r) {
            int mid = l + (r - l) / 2;
            int midVal = mArr.get(mid);
            if (midVal == target) return mid;
            else if (midVal < target) {
                if (acend) l = mid + 1;
                else r = mid - 1;
            }
            else {
                if (acend) r = mid - 1;
                else l = mid + 1;
            }
        }
        return -1;
    }
};