class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<bool> hasTargetVal(3, false);
        for(int i = 0; i < triplets.size(); ++i) {
            if (triplets[i][0] > target[0] || triplets[i][1] > target[1] || triplets[i][2] > target[2]) {
                continue;
            }
            else {
                for(int j = 0; j < 3; ++j) {
                    if (!hasTargetVal[j] && triplets[i][j] == target[j]) {
                        hasTargetVal[j] = true;
                    }
                }
            }
        }

        return hasTargetVal[0] && hasTargetVal[1] && hasTargetVal[2];
    }
};
