class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // find the closest num's index first
        // and then use two pointers to add candidates int the answer
        int n = arr.size();
        int l = binarySearch(arr, x) - 1;
        int r = l + 1;
        int remain = k;
        while (remain > 0) {
            if (l >= 0 && r < n) {
                int distL = abs(arr[l] - x);
                int distR = abs(arr[r] - x);
                if (distL <= distR) {
                    l--;
                }
                else {
                    r++;
                }
            }
            else if (l >= 0) {
                l--;
            }
            else if (r < n) {
                r++;
            }
            else {
                break;
            }
            --remain;
        }
        return vector<int>(arr.begin() + l + 1, arr.begin() + r);
    }

    int binarySearch(vector<int>& arr, int target) {
        int l = 0, r = arr.size() - 1;
        while(l < r) {
            int mid = l + (r - l) / 2;
            if (arr[mid] < target) {
                l = mid + 1;
            }
            else {
                r = mid;
            }
        }
        return l;
    }
};