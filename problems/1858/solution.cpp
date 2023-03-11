class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    int words = 0;
    string word;
    
    TrieNode() {}
};

class Solution {
private:
    TrieNode *root = new TrieNode();
    
    void insert(string& word) {
        TrieNode *node = root;
        int ws = size(word);
        
        for (const char& ch: word) {
            if (not node->children[ch]) {
                node->children[ch] = new TrieNode();
            }
            
            node = node->children[ch];
            node->words++;
        }
        
        node->word = word;
    }
public:
    string longestWord(vector<string>& words) {
        unordered_set<string> prefs = {begin(words), end(words)};
        
        sort(begin(words), end(words), [](const string& a, const string& b) {
            if (size(a) == size(b)) {
                return a < b;
            }
            
            return size(a) > size(b);
        });
        
        for (const string& word: words) {
            string curWord;
            bool found = true;
            
            for (int i = 0; i < size(word) - 1; i++) {
                curWord.push_back(word[i]);
                
                if (not prefs.count(curWord)) {
                    found = false;
                    break;
                }
            }
            
            if (found) {
                return word;
            }
        }
        
        // copy(begin(words), end(words), ostream_iterator<string>(cout, ", "));
        // cout << endl;
        
        return "";
    }
};