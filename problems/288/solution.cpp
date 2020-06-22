class ValidWordAbbr {
private:
    unordered_map<string, bool> abbrs;
    unordered_set<string> dict;
    
    string getAbbr(const string& s) {
        if (s.size() <= 2) {
            return s;
        }
        
        return s[0] + to_string(s.size() - 2) + s.back();
    }
public:
    ValidWordAbbr(vector<string>& dictionary) {
        dict = unordered_set<string>(begin(dictionary), end(dictionary));
        
        for (const string& s: dict) {
            string abbr = getAbbr(s);
            
            abbrs[abbr] = abbrs.find(abbr) == abbrs.end();
        }
    }
    
    bool isUnique(string word) {
        string abbr = getAbbr(word);
        
        return abbrs.find(abbr) == abbrs.end() or (abbrs[abbr] and dict.count(word));
    }
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr* obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj->isUnique(word);
 */