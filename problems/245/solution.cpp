class Solution {
public:
    int shortestWordDistance(vector<string>& wordsDict, string word1, string word2) {
        long long int ans = INT_MAX, i = ans, j = -i;
        
        for (int k = 0; k < size(wordsDict); k++) {
            if (wordsDict[k] == word1) {
                i = k;
            }
            
            if (wordsDict[k] == word2) {
                if (word1 == word2) {
                    i = j;
                }
                
                j = k;
            }
            
            ans = min(ans, abs(i - j));
        }
        
        return ans;
    }
};