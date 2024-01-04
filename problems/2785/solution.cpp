class Solution {
private:
    
public:
    string sortVowels(string s) {
        unordered_set<char> vowels = {
            'a', 'A', 'e', 'E', 'i', 'I', 'o', 'O', 'u', 'U'
        };
        unordered_map<char, int> cnt;
        string order = "AEIOUaeiou";
        
        for (const char& ch: s) {
            if (vowels.count(ch)) {
                cnt[ch]++;
            }
        }
        
        for (int i = 0, j = 0; i < size(s); i++) {
            if (vowels.count(s[i])) {
                while (cnt[order[j]] == 0) {
                    j++;
                }
                
                s[i] = order[j];
                cnt[order[j]]--;
            }
        }
        
        return s;
    }
};