class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int word1idx = -1, word2idx = -1, dist = INT_MAX;
        
        for (int i = 0; i < words.size(); i++) {
            if (words[i] == word1) {
                word1idx = i;
            }
            
            if (words[i] == word2) {
                word2idx = i;
            }
            
            if (word1idx != -1 && word2idx != -1) {
                dist = min(dist, abs(word1idx - word2idx));
            }
        }
        
        return dist;
    }
};