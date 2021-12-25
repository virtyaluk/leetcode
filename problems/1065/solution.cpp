class Trie {
public:
    unordered_map<char, Trie*> um;
    bool isWord;
};

class Solution {
private:
    Trie* trie = new Trie();
    
    void insert(const string& word) {
        Trie* node = trie;
        
        for (const char& ch: word) {
            if (not node->um.count(ch)) {
                node->um[ch] = new Trie();
            }
            
            node = node->um[ch];
        }
        
        node->isWord = true;
    }
public:
    vector<vector<int>> indexPairs(string text, vector<string>& words) {
        vector<vector<int>> ans;
        
        for (const string& word: words) {
            insert(word);
        }
        
        for (int i = 0; i < size(text); i++) {
            Trie* node = trie;
            
            for (int j = i; j < size(text); j++) {
                if (not node->um.count(text[j])) {
                    break;
                }
                
                node = node->um[text[j]];
                
                if (node->isWord) {
                    ans.push_back({i, j});
                }
            }
        }
        
        return ans;
    }
};