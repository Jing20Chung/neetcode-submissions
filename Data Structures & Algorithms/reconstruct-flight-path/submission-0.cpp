class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, queue<string>> adj;

        sort(tickets.begin(), tickets.end());
        for(auto ticket: tickets) {
            adj[ticket[0]].push(ticket[1]);
        }

        vector<string> res;
        dfs("JFK", adj, res);
        reverse(res.begin(), res.end());
        return res;
    }

    void dfs(string start, unordered_map<string, queue<string>>& adj, vector<string>& res) {
        while(!adj[start].empty()) {
            string next = adj[start].front();
            adj[start].pop();
            dfs(next, adj, res);
        }
        res.push_back(start);
    }
};
