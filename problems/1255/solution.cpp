class Solution {
void dfs(vector<string>& words, vector<int>& price, vector<int>& cur, vector<int>& used, int idx, int score, int& ans) {
    for (int i = 0; i < 26; i++) {
        if (used[i] > cur[i]) {
            return;
        }
    }
    
    ans = max(ans, score);
    
    for (int i = idx; i < size(words); i++) {
        for (const char& ch: words[i]) {
            used[ch - 'a']++;
            score += price[ch - 'a'];
        }
        
        dfs(words, price, cur, used, i + 1, score, ans);
        
        for (const char& ch: words[i]) {
            used[ch - 'a']--;
            score -= price[ch - 'a'];
        }
    }
}

public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int ans = 0;
        vector<int> cur(26, 0), used(26, 0);
        
        for (const char& ch: letters) {
            cur[ch - 'a']++;
        }
        
        dfs(words, score, cur, used, 0, 0, ans);
        
        return ans;
    }
};