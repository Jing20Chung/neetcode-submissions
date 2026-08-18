// Definition for a Pair
// class Pair {
// public:
//     int key;
//     string value;
//
//     Pair(int key, string value) : key(key), value(value) {}
// };
class Solution {
public:
    vector<Pair> mergeSort(vector<Pair>& pairs) {
        if (pairs.empty()) return {};
        mergeSortHelper(0, pairs.size() - 1, pairs);
        return pairs;
    }

    void mergeSortHelper(int s, int e, vector<Pair>& pairs) {
        if (s >= e) return;
        int mid = s + (e - s) / 2;
        mergeSortHelper(s, mid, pairs);
        mergeSortHelper(mid + 1, e, pairs);
        merge(s, mid, e, pairs);
    }

    void merge(int s, int mid, int e, vector<Pair>& pairs) {
        int i = s, j = mid + 1;
        vector<Pair> res;
        while (i <= mid || j <= e) {
            if (i > mid) {
                res.push_back(pairs[j++]);
            }
            else if (j > e) {
                res.push_back(pairs[i++]);
            }
            else {
                if (pairs[i].key <= pairs[j].key) {
                    res.push_back(pairs[i++]);
                }
                else {
                    res.push_back(pairs[j++]);
                }
            }
        }

        for(int k = s; k <= e; ++k) {
            pairs[k] = res[k - s];
        }
    }
};
