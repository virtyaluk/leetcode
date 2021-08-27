class Solution {
public:
    unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
    
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        vector<string> ans;
        unordered_set<string> wordsPerfect;
        unordered_map<string, string> wordsCap, wordsVow;
        
        for (const string& word: wordlist) {
            wordsPerfect.insert(word);
            
            string wordLow = to_lower(word);
            
            if (not wordsCap.count(wordLow)) {
                wordsCap[wordLow] = word;
            }
            
            string wordLowDv = devowel(wordLow);
            
            if (not wordsVow.count(wordLowDv)) {
                wordsVow[wordLowDv] = word;
            }
        }
        
        for (const string& q: queries) {
            ans.push_back(query(wordsPerfect, wordsCap, wordsVow, q));
        }
        
        return ans;
    }
    
    string to_lower(string str) {
        string ans;
        
        for (const char& ch: str) {
            ans += tolower(ch);
        }
        
        return ans;
    }
    
    string devowel(string str) {
        string ans;
        
        for (const char& ch: str) {
            if (vowels.count(ch)) {
                ans += '*';
            } else {
                ans += ch;
            }
        }
        
        return ans;
    }
    
    string query(unordered_set<string>& wordsPerfect, unordered_map<string, string>& wordsCap, unordered_map<string, string>& wordsVow, const string& q) {
        if (wordsPerfect.count(q)) {
            return q;
        }
        
        string ql = to_lower(q);
        
        if (wordsCap.count(ql)) {
            return wordsCap[ql];
        }
        
        string qlv = devowel(ql);
        
        if (wordsVow.count(qlv)) {
            return wordsVow[qlv];
        }
        
        return "";
    }
};