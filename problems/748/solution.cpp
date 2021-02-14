class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        string ans;
        vector<int> target(26, 0);
        
        for (char ch: licensePlate) {
            if (isalpha(ch)) {
                target[tolower(ch) - 'a']++;
            }
        }
        
        for (string& word: words) {
            vector<int> wordCounter(26, 0);
            
            for (char ch: word) {
                if (isalpha(ch)) {
                    wordCounter[tolower(ch) - 'a']++;
                }
            }
            
            bool matches = true;
            
            for (int i = 0; i < target.size(); i++) {
                if (target[i] > wordCounter[i]) {
                    matches = false;
                    break;
                }
            }
            
            if (matches && (ans.empty() || word.size() < ans.size())) {
                ans = word;
            }
        }
        
        return ans;
    }
};