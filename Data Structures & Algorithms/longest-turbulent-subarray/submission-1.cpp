class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int l = 0, r = 1, ans = 1;
        string prev = "";
        const int n = arr.size();
        while(r < n) {
            if (arr[r] < arr[r - 1] && prev != "<") {
                ans = max(ans, r - l + 1);
                r++;
                prev = "<";
            }
            else if (arr[r] > arr[r - 1] && prev != ">") {
                ans = max(ans, r - l + 1);
                r++;
                prev = ">";
            }
            else {
                r = (arr[r] == arr[r - 1])? r + 1: r;
                l = r - 1;
                prev = "";
            }
        }
        return ans;
    }
};