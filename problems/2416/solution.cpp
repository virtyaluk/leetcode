class Trie {
public:
    int count;
    unordered_map<char, Trie*> child;
};

class Solution {
private:
    Trie* root = nullptr;
    
    void insert(const string& word) {
        Trie* node = root;
        
        for (const char& ch: word) {
            if (not node->child.count(ch)) {
                node->child[ch] = new Trie();
            }
            
            node->child[ch]->count++;
            node = node->child[ch];
        }
    }
    
    int search(const string& word) {
        int ans = 0;
        Trie* node = root;
        
        for (const char& ch: word) {
            if (not node->child.count(ch)) {
                break;
            }
            
            node = node->child[ch];
            ans += node->count;
        }
        
        return ans;
    }
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        vector<int> ans;
        root = new Trie();
        
        for (const string& word: words) {
            insert(word);
        }
        
        for (const string& word: words) {
            ans.push_back(search(word));
        }
        
        return ans;
    }
};