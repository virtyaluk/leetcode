class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int ans = 0;
        
        for (const string& sent: sentences) {
            int wordsCount = 1 + count(begin(sent), end(sent), ' ');
            ans = max(ans, wordsCount);
        }
        
        return ans;
    }
};