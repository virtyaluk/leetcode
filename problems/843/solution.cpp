/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
    int match(string a, string b) {
        int ans = 0;
        
        for (int i = 0; i < size(a); i++) {
            ans += a[i] == b[i];
        }
        
        return ans;
    }
    
    void findSecretWord(vector<string>& wordlist, Master& master) {
        for (int i = 0, matches = 0; i < 10 and matches < 6; i++) {
            vector<vector<int>> count(6, vector<int>(26));
            int best = 0;
            string wordToGuess = wordlist.front();
            
            for (const string& word: wordlist) {
                for (int i = 0; i < 6; i++) {
                    count[i][word[i] - 'a']++;
                }
            }
            
            for (const string& word: wordlist) {
                int score = 0;
                
                for (int i = 0; i < 6; i++) {
                    score += count[i][word[i] - 'a'];
                }
                
                if (score > best) {
                    best = score;
                    wordToGuess = word;
                }
            }
            
            matches = master.guess(wordToGuess);
            vector<string> newWordlist;
            
            for (const string& word: wordlist) {
                if (match(wordToGuess, word) == matches) {
                    newWordlist.push_back(word);
                }
            }
            
            wordlist = newWordlist;
        }
    }
};