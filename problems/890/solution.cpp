class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        vector<char> patFreqSorted = getCharsFreqMapSorted(pattern);
        
        for (const string& word: words) {
            if (patFreqSorted == getCharsFreqMapSorted(word)) {
                ans.push_back(word);
            }
        }
        
        return ans;
    }
    
    vector<char> getCharsFreqMapSorted(const string& str) {
        vector<char> ans;
        unordered_map<char, unsigned short int> um;
        
        for (const char& ch: str) {
            if (not um.count(ch)) {
                um[ch] = um.size() + 1;
            }
            
            ans.push_back('a' + um[ch]);
        }
        
        return ans;
    }
};