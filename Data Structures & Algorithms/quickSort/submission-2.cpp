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
    vector<Pair> quickSort(vector<Pair>& pairs) {
        helper(0, pairs.size() - 1, pairs);
        return pairs;
    }

    void helper(int s, int e, vector<Pair>& pairs) {
        if (s >= e) return;
        int pVal = pairs[e].key;
        int l = s;
        for(int k = s; k < e; ++k) {
            if (pairs[k].key < pVal) {
                swap(pairs[l++], pairs[k]);
            }
        }
        swap(pairs[l], pairs[e]);
        helper(s, l - 1, pairs);
        helper(l + 1, e, pairs);
    }
};
