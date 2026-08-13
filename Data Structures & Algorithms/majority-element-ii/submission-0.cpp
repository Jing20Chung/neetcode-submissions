class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // because dominate element won't exceed two numbers
        // extend Boyer-Moore Voting Algorithm is doable
        int m = nums.size() / 3;
        int num1 = -1;
        int num2 = -1;
        int cnt1 = 0;
        int cnt2 = 0;
        for(int num: nums) {
            if (num == num1) {
                ++cnt1;
            }
            else if (num == num2) {
                ++cnt2;
            }
            else if (cnt1 == 0) {
                num1 = num;
                cnt1 = 1;
            }
            else if (cnt2 ==0) {
                num2 = num;
                cnt2 = 1;
            }
            else {
                cnt1--;
                cnt2--;
            }
        }

        cnt1 = 0;
        cnt2 = 0;
        for(int num: nums) {
            if (num == num1) {
                ++cnt1;
            }
            else if (num == num2) {
                ++cnt2;
            }
        }
        vector<int> ans;
        // verify cnt1 and cnt2 is > n/3
        if (cnt1 > m) ans.push_back(num1);
        if (cnt2 > m) ans.push_back(num2);
        return ans;
    }
};