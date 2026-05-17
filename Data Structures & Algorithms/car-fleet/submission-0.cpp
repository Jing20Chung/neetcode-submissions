class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, int>> posSpeed;
        posSpeed.reserve(n);
        for(int i = 0; i < n; i++) {
            posSpeed.push_back({position[i], speed[i]});
        }
        sort(posSpeed.begin(), posSpeed.end(), greater<pair<int, int>>());

        stack<double> fleets;
        for(const auto& [pos, spd]: posSpeed) {
            double arriveTime = (double)(target - pos)/spd;
            if (fleets.empty() || fleets.top() < arriveTime) {
                fleets.push(arriveTime);
            }
        }
        return fleets.size();
    }
};
