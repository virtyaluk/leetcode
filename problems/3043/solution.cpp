class Trie {
public:
    unordered_map<char, Trie*> child;
};

class Solution {
private:
    Trie *trie = new Trie();
    
    void insert(const string& str) {
        Trie *cur = trie;
        
        for (const char& ch: str) {
            if (not cur->child.count(ch)) {
                cur->child[ch] = new Trie();
            }
            
            cur = cur->child[ch];
        }
    }
    
    int check(const string& str) {
        Trie * cur = trie;
        int ans = 0;
        
        for (const char& ch: str) {
            if (not cur->child.count(ch)) {
                return ans;
            }
            
            cur = cur->child[ch];
            ans++;
        }
        
        return ans;
    }
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int ans = 0;
        
        for (const int& num: arr1) {
            insert(to_string(num));
        }
        
        for (const int& num: arr2) {
            ans = max(ans, check(to_string(num)));
        }
        
        return ans;
    }
};