class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair<long long, int>> dists;
        for(int i = 0; i < points.size(); i++) {
            long long dist = points[i][0] * points[i][0] + points[i][1] * points[i][1]; 
            dists.push_back({dist, i});
        }
        quickSelect(dists, 0, dists.size() - 1, k - 1);

        vector<vector<int>> ans;
        for(int i = 0; i < k; i++) {
            ans.push_back(points[dists[i].second]);
        }
        return ans;
    }

    void quickSelect(vector<pair<long long, int>>& dists, int l, int r, int target) {
        if (l >= r) return;
        int result = partition(dists, l, r);
        if (result == target) return;
        if (result < target) {
            return quickSelect(dists, result + 1, r, target);
        }
        else {
            return quickSelect(dists, l, result - 1, target);
        }
    }

    int partition(vector<pair<long long, int>>& dists, int l, int r) {
        int s = l;
        int cur = s;
        int pivotIndex = l + rand() % (r - l + 1);
        swap(dists[pivotIndex], dists[r]);
        long long pivot = dists[r].first;
        while (cur < r) {
            if (dists[cur].first <= pivot) {
                swap(dists[s], dists[cur]);
                s++;
            }
            cur++;
        }
        swap(dists[s], dists[r]);
        return s;
    }
};
