
class UnionFind {
private:
    vector<int> parent;
    vector<int> rank;
public:
    UnionFind(int n) {
        parent.resize(n);
        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }

        rank.resize(n, 1);
    }

    int find(int n) {
        if (parent[n] == n) return n;
        return parent[n] = find(parent[n]);
    }

    bool unionNodes(int n1, int n2) {
        int root1 = find(n1);
        int root2 = find(n2);
        if (root1 == root2) return false;

        if (rank[root1] > rank[root2]) {
            parent[root2] = root1;
        }
        else if (rank[root1] < rank[root2]) {
            parent[root1] = root2;
        }
        else {
            parent[root2] = root1;
            rank[root1] += rank[root2];
        }
        return true;
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        if (accounts.empty()) return {};
        // the same email in different accounts --> those accounts belongs to 
        // the same person

        // union all the accounts first
        int n = accounts.size();
        UnionFind uf(n);

        // need a dict to see if the email has appeared before
        unordered_map<string, int> emailToAccIdx;

        for(int accIdx = 0; accIdx < n; ++accIdx) {
            for(int j = 1; j < accounts[accIdx].size(); ++j) { // loop all emails under this account
                string email = accounts[accIdx][j];
                if (emailToAccIdx.contains(email)) {
                    // union those two accounts
                    uf.unionNodes(emailToAccIdx[email], accIdx);
                }
                else {
                    emailToAccIdx[email] = accIdx;
                }
            }
        }

        // collect all emails in the same union
        unordered_map<int, vector<string>> mergedEmail;
        // use the map that already eliminate dulplicated emails -> emailToAccIdx
        for(const auto&[email, accIdx]: emailToAccIdx) {
            int root = uf.find(accIdx);
            mergedEmail[root].push_back(email);
        }
        
        // build return value
        vector<vector<string>> result;
        for(auto&[accIdx, emails]: mergedEmail) {
            vector<string> acc;
            string name = accounts[accIdx][0];
            acc.push_back(name);
            sort(emails.begin(), emails.end());
            acc.insert(acc.end(), emails.begin(), emails.end());
            result.push_back(acc);
        }
        return result;
    }
};
