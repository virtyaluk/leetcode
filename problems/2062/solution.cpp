class Solution {
private:
    bool isVowel(const char& ch) {
        return ch == 'a' or ch == 'e' or ch == 'i' or ch == 'o' or ch == 'u';
    }
public:
    int countVowelSubstrings(string word) {
        int ans = 0, n = size(word);
        unordered_map<char, int> um;
        
        for (int i = 0; i < n; i++) {
            um.clear();

            for (int j = i; j < n and isVowel(word[j]); j++) {
                um[word[j]]++;
                ans += size(um) == 5;
            }
        }
        
        return ans;
    }
};