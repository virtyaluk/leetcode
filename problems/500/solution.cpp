class Solution {
private:
    string rows[3] = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};
    
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> ans;
        unordered_map<char, int> m;
        
        for (int i = 0; i < 3; i++) {
            for (const char& ch: rows[i]) {
                m[tolower(ch)] = i;
                m[toupper(ch)] = i;
            }
        }
        
        for (const string& word: words) {
            unordered_set<int> count;
            
            for (const char& ch: word) {
                count.insert(m[ch]);
            }
            
            if (count.size() == 1) {
                ans.push_back(word);
            }
        }
        
        return ans;
    }
};