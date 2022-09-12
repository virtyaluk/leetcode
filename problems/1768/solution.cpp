class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n = min(size(word1), size(word2));
        string ans;
        
        for (int i = 0; i < n; i++) {
            ans.push_back(word1[i]);
            ans.push_back(word2[i]);
        }
        
        if (size(word1) == n) {
            ans += word2.substr(n);
        } else {
            ans += word1.substr(n);
        }
        
        return ans;
    }
};