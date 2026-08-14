class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // find the closest num's index first
        // and then use two pointers to add candidates int the answer
        int n = arr.size();
        int l = binarySearch(arr, x);
        int r = l + 1;
        int remain = k;
        deque<int> dq;
        while (remain > 0) {
            if (l >= 0 && r < n) {
                int distL = abs(arr[l] - x);
                int distR = abs(arr[r] - x);
                if (distL <= distR) {
                    dq.push_front(arr[l--]);
                }
                else {
                    dq.push_back(arr[r++]);
                }
            }
            else if (l >= 0) {
                dq.push_front(arr[l--]);
            }
            else if (r < n) {
                dq.push_back(arr[r++]);
            }
            else {
                break;
            }
            --remain;
        }
        vector<int> ans(dq.begin(), dq.end());
        return ans;
    }

    int binarySearch(vector<int>& arr, int target) {
        int l = 0, r = arr.size() - 1;
        while(l <= r) {
            int mid = l + (r - l) / 2;
            if (arr[mid] == target) {
                return mid;
            }
            else if (arr[mid] < target) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        return r;
    }
};