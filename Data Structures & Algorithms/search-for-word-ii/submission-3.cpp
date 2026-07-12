class Solution {
public:
    Solution(){
        root = new Node();
    }
    ~Solution(){
        clear(root);
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        if (board.empty() || board[0].empty()) return {};
        int m = board.size();
        int n = board[0].size();

        build(words);
        vector<string> ans = {};
        for(int r = 0; r < board.size(); ++r) {
            for(int c = 0; c < board[0].size(); ++c) {
                if (root->children[board[r][c] - 'a'] != nullptr && root->children[board[r][c] - 'a']->pathCount != 0) {
                    dfs(root->children[board[r][c] - 'a'], r, c, m, n, board, ans);
                }
            }
        }
        return ans;
    }
private:
    struct Node {
        Node(): isWord(false), word(""), pathCount(0), children(vector<Node*>(26, nullptr)) {}
        bool isWord;
        string word;
        int pathCount;
        vector<Node*> children;
    };
    Node* root;

    void build(vector<string>& words) {
        clear(root);
        root = new Node();
        for(const string word: words) {
            insert(word);
        }
    }

    void insert(const string& word) {
        Node* curr = root;
        for(const char& c: word) {
            int index = c - 'a';
            if (curr->children[index] == nullptr) {
                curr->children[index] = new Node();
            }
            curr = curr->children[index];
            curr->pathCount++;
        }
        curr->word = word;
        curr->isWord = true;
    }

    void dfs(Node* node, int r, int c, const int& m, const int& n, vector<vector<char>>& board, vector<string>& ans){
        if (node->isWord)
        {
            ans.push_back(node->word);
            removeWord(ans[ans.size() - 1]);
        }

        char curChar = board[r][c];
        board[r][c] = '.';

        static const int dr[4] = {1, -1, 0, 0};
        static const int dc[4] = {0, 0, 1, -1};

        for(int i = 0; i < 4; ++i) {
            int newR = r + dr[i];
            int newC = c + dc[i];
            if (newR < 0 || newR >= m || newC < 0 || newC >= n || board[newR][newC] == '.' || !node->children[board[newR][newC] - 'a'] || node->children[board[newR][newC] - 'a']->pathCount == 0) continue;
            dfs(node->children[board[newR][newC] - 'a'], newR, newC, m, n, board, ans);
        }
        board[r][c] = curChar;
    }

    void clear(Node* node){
        if (node == nullptr) return;
        for(int i = 0; i < 26; i++) {
            if (node->children[i] != nullptr) {
                clear(node->children[i]);
            }
        }
        delete node;
    }

    bool removeWord(const string& word) {
        if (!root) return false;
        Node* curr = root;
        for(const char& c: word) {
            if (curr->children[c - 'a'] != nullptr) {
                curr->children[c - 'a']->pathCount--;
                curr = curr->children[c - 'a'];
            }
            else {
                return false;
            }
        }
        curr->isWord = false;
        return true;
    }
};
