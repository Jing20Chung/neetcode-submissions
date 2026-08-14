class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        // greedy?
        // when found the first asteroid which is not the same
        // direction, calculate the explosion and 
        // if remain the same direction, delete the opponent,
        // continue to next asteroid
        // if got deleted, change direction to the opponent and
        // loop backwards

        // this would be the O(N^2) solution

        // any better one?

        vector<int> ans;
        for(int num: asteroids) {
            if (num > 0) {
                ans.push_back(num);
            }
            else {
                int w = abs(num);
                while (!ans.empty() && ans.back() > 0 && ans.back() < w) ans.pop_back();
                if (ans.empty() || ans.back() < 0) {
                    ans.push_back(num);
                }
                else if (ans.back() == w) {
                    ans.pop_back();
                }
            }
        }

        return ans;
    }
};