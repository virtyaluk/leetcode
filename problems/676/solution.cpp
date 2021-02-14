class MagicDictionary {
private:
    unordered_set<string> words;
    unordered_map<string, int> count;
    char tmp = '*';
    
    vector<string> nextWord(string& word) {
        vector<string> ans;
        
        for (int i = 0; i < size(word); i++) {
            swap(word[i], tmp);
            ans.push_back(word);
            swap(word[i], tmp);
        }
        
        return ans;
    }
public:
    MagicDictionary() {}
    
    void buildDict(vector<string> dictionary) {
        for (string& word: dictionary) {
            words.insert(word);
            
            for (const string& nw: nextWord(word)) {
                count[nw]++;
            }
        }
    }
    
    bool search(string searchWord) {
        for (const string& nw: nextWord(searchWord)) {
            if (count[nw] > 1 or count[nw] == 1 and not words.count(searchWord)) {
                return true;
            }
        }
        
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */