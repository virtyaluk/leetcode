class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> ans;
        unordered_map<string, int> um;
        
        for (const string& str: words) {
            um[str] = size(um);
        }
        
        for (auto &[word, idx]: um) {
            string reversed(rbegin(word), rend(word));
            
            if (um.count(reversed) and idx != um[reversed]) {
                ans.push_back({idx, um[reversed]});
            }
            
            for (string suf: getAllSuffixes(word)) {
                string reversedSuf(rbegin(suf), rend(suf));
                
                if (um.count(reversedSuf) and idx != um[reversedSuf]) {
                    ans.push_back({um[reversedSuf], idx});
                }
            }
            
            for (string pref: getAllPrefixes(word)) {
                string reversedPref(rbegin(pref), rend(pref));
                
                if (um.count(reversedPref) and idx != um[reversedPref]) {
                    ans.push_back({idx, um[reversedPref]});
                }
            }
        }
        
        return ans;
    }
    
    vector<string> getAllSuffixes(string word) {
        vector<string> ans;
        
        for (int i = 0; i < size(word); i++) {
            if (isPalindrome(word, 0, i)) {
                ans.push_back(word.substr(i + 1));
            }
        }
        
        return ans;
    }
    
    vector<string> getAllPrefixes(string word) {
        vector<string> ans;
        
        for (int i = 0; i < size(word); i++) {
            if (isPalindrome(word, i, size(word) - 1)) {
                ans.push_back(word.substr(0, i));
            }
        }
        
        return ans;
    }
    
    bool isPalindrome(string& str, int lo, int hi) {
        while (lo <= hi) {
            if (str[lo++] != str[hi--]) {
                return false;
            }
        }
        
        return true;
    }
};