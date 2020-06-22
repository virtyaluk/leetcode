class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    string word;
    
    TrieNode() {}
};

class Solution {
private:
    TrieNode *root = new TrieNode();
    
    void insert(string& word) {
        TrieNode *node = root;
        
        for (const char& ch: word) {
            if (not node->children.count(ch)) {
                node->children[ch] = new TrieNode();
            }
            
            node = node->children[ch];
        }

        node->word = word;
    }
    
    void dfs(vector<vector<char>>& board, int x, int y, TrieNode* node, vector<string>& ans) {
        if (x < 0 or x >= size(board) or y < 0 or y >= size(board.back()) or board[x][y] == '#' or not node->children.count(board[x][y])) {
            return;
        }
        
        char lastChar = board[x][y];
        node = node->children[lastChar];
        
        if (not empty(node->word)) {
            ans.push_back(node->word);
            node->word.clear(); // eliminate duplicates
        }
        
        board[x][y] = '#';
        
        dfs(board, x + 1, y, node, ans);
        dfs(board, x - 1, y, node, ans);
        dfs(board, x, y + 1, node, ans);
        dfs(board, x, y - 1, node, ans);
        
        board[x][y] = lastChar;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ans;
        int m = size(board), n = size(board.back());
        
        for (string& word: words) {
            insert(word);
        }
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dfs(board, i, j, root, ans);
                // if (root->children.count(board[i][j])) {
                //     dfs(board, i, j, root->children[board[i][j]], ans);
                // }
            }
        }
        
        return ans;
    }
};