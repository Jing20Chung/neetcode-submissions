class Solution {
private:
    int partition(vector<vector<int>>& dists, int l, int r) {
        int pIdx = l + rand() % (r - l + 1);
        int pVal = dists[pIdx][0];
        swap(dists[r], dists[pIdx]);
        int s = l;
        while(l < r) {
            if (dists[l][0] <= pVal) {
                swap(dists[s], dists[l]);
                s++;
            }
            l++;
        }
        swap(dists[s], dists[r]);
        return s;
    }
    void quickSelect(vector<vector<int>>& dists, int left, int right, int k) {
        if (left >= right) return;
        int rank = partition(dists, left, right);
        if (rank < k) {
            quickSelect(dists, rank + 1, right, k);
        }
        else if (rank > k) {
            quickSelect(dists, left, rank - 1, k);
        }
        else {
            return;
        }
    }
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> dists;
        for(int i = 0; i < points.size(); i++) {
            int dist = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            dists.push_back({dist, i});
        }
        quickSelect(dists, 0, points.size() - 1, k - 1);
        
        vector<vector<int>> ans;
        for(int i = 0; i < k; i++) {
            ans.push_back(points[dists[i][1]]);
        }
        return ans;
    }
};
