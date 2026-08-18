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
    vector<vector<Pair>> insertionSort(vector<Pair>& pairs) {
        vector<vector<Pair>> ans;
        int n = pairs.size();
        for(int i = 0; i < n; ++i) {
            int j = i - 1;
            while (j >= 0 && pairs[j].key > pairs[j + 1].key) {
                swap(pairs[j], pairs[j + 1]);
                --j;
            }
            ans.push_back(pairs);
        }
        return ans;
    }
};
