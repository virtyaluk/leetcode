class Solution {
public:
    int maxProduct(vector<string>& words) {
        int ans = 0;
        unordered_map<string, int> um;
        
        for (const string& word: words) {
            um[word] = token(word);
        }
        
        for (const string& word1: words) {
            for (const string& word2: words) {
                if ((um[word1] & um[word2]) == 0) {
                    ans = max(ans, (int) (word1.size() * word2.size()));
                }
            }
        }
        
        return ans;
    }
    
    int token(const string& str) {
        int token = 0;
        
        for (const char& ch: str) {
            token |= 1ul << (ch - 'a');
        }
        
        return token;
    }
};