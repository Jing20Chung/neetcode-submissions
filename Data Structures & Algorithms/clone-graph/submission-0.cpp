/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        unordered_map<Node*, Node*> nodeMap;
        nodeMap[node] = new Node(node->val);
        queue<Node*> q;
        q.push(node);

        while(!q.empty()) {
            Node* cur = q.front();
            q.pop();
            for(Node* neighbor: cur->neighbors) {
                if(nodeMap.find(neighbor) == nodeMap.end()) {
                    nodeMap[neighbor] = new Node(neighbor->val);
                    q.push(neighbor);
                }
                nodeMap[cur]->neighbors.push_back(nodeMap[neighbor]);
            }
        }
        return nodeMap[node];
    }
};
