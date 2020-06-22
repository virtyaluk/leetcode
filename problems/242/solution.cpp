class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        
        vector<int> counter(26);
        
        for (const char& ch: s) {
            counter[ch - 'a']++;
        }
        
        for (const char& ch: t) {
            counter[ch - 'a']--;
        }
        
        return count(begin(counter), end(counter), 0) == 26;
    }
};