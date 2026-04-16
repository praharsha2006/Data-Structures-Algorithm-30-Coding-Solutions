class TrieNode {
public:
    TrieNode* child[26];
    string word = "";

    TrieNode() {
        for (int i = 0; i < 26; i++) child[i] = NULL;
    }
};

class Solution {
public:
    vector<string> result;

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();

        for (string word : words) {
            TrieNode* node = root;
            for (char c : word) {
                int idx = c - 'a';
                if (!node->child[idx]) node->child[idx] = new TrieNode();
                node = node->child[idx];
            }
            node->word = word;
        }

        int m = board.size(), n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dfs(board, i, j, root);
            }
        }

        return result;
    }

    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* node) {
        char c = board[i][j];

        if (c == '#' || !node->child[c - 'a']) return;

        node = node->child[c - 'a'];

        if (node->word != "") {
            result.push_back(node->word);
            node->word = "";
        }

        board[i][j] = '#';

        int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

        for (auto& d : dir) {
            int x = i + d[0], y = j + d[1];

            if (x >= 0 && y >= 0 && x < board.size() && y < board[0].size()) {
                dfs(board, x, y, node);
            }
        }

        board[i][j] = c;
    }
};