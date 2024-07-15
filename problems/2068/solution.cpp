class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        vector<int> a(26), b(26);
        
        for (const char& ch: word1) {
            a[ch - 'a']++;
        }
        
        for (const char& ch: word2) {
            b[ch - 'a']++;
        }
        
        for (int i = 0; i < 26; i++) {
            if (abs(a[i] - b[i]) > 3) {
                return false;
            }
        }
        
        return true;
    }
};