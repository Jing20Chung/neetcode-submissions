class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> h;
        h.reserve(heights.size() + 2);
        h.push_back(0);
        h.insert(h.end(), heights.begin(), heights.end());
        h.push_back(0);

        int maxArea = 0;
        stack<int> stk;
        for(int i = 0; i < h.size(); i++) {
            while(!stk.empty() && h[stk.top()] > h[i]) {
                int curTopH = h[stk.top()];
                stk.pop();
                maxArea = max(maxArea, curTopH * (i - stk.top() - 1));
            }
            stk.push(i);
        }

        return maxArea;
    }
};
