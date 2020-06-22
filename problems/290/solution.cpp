class Solution {
public:
    bool wordPattern(string pattern, string str) {
        vector<string> words = split(str, ' ');
        
        if (pattern.size() != words.size()) {
            return false;
        }
        
        unordered_map<string, int> strMap;
        vector<string> chMap(26, "");
        
        for (int i = 0; i < words.size(); i++) {
            int ch = pattern[i];
            string word = words[i];
            
            if (strMap.find(word) == strMap.end() && chMap[ch - 'a'] == "") {
                strMap[word] = ch;
                chMap[ch - 'a'] = word;
            } else if (strMap[word] != ch || chMap[ch - 'a'] != word) {
                return false;
            }
        }
        
        return true;
    }
    
    vector<string> split(string str, char delim) {
        istringstream iss(str);
        string word;
        vector<string> words;
        
        while(getline(iss, word, delim)) words.push_back(word);
        
        return words;
    }
};