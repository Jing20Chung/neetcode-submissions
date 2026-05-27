class Node {
public:
    Node() {}
    Node(char c) {
        this->c = c;
        isWord = false;
        word;
    }

    char c;
    bool isWord;
    string word;
    Node* next[26] = {nullptr};
};

class Solution {
public:
    Solution() {
        head = new Node();
    }
    ~Solution() {
        clear(head);
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        if (head) { clear(head); head = new Node(); }
        build(words);
        vector<string> res;
        for(int r = 0; r < board.size(); r++) {
            for(int c = 0; c < board[0].size(); c++) {
                dfs(r, c, board, head, res);
            }
        }
        return res;
    }
private:
    Node* head;
    void dfs(int r, int c, vector<vector<char>>& board, Node* node, vector<string>& res) {
        char ch = board[r][c];
        if (ch == '#' || !node->next[ch - 'a']) return;

        node = node->next[ch - 'a'];
        if (node->isWord) {
            res.push_back(node->word);
            node->isWord = false;
        }

        board[r][c] = '#';
        int dr[] = {0, 0, 1, -1}, dc[] = {1, -1, 0, 0};
        for(int i = 0; i < 4; i++) {
            int nextR = r + dr[i];
            int nextC = c + dc[i];
            if (nextR >= 0 && nextC >= 0 && nextR < board.size() && nextC < board[0].size()) {
                dfs(nextR, nextC, board, node, res);
            }
        }
        board[r][c] = ch;
    }

    void build(vector<string>& words){
        head = new Node();
        for(string& word: words) {
            insert(word);
        }
    }
    
    void insert(string word) {
        int idx = 0;
        Node* cur = head;
        while(idx < word.size()) {
            char c = word[idx];
            if(!cur->next[c - 'a']) {
                cur->next[c - 'a'] = new Node(c);
            }
            cur = cur->next[c - 'a'];
            idx++;
        }
        cur->isWord = true;
        cur->word = word;
    }

    void clear(Node* node) {
        for(int i = 0; i < 26; i++) {
            if(node->next[i]) {
                clear(node->next[i]);
            }
        }
        delete node;
    }
};
