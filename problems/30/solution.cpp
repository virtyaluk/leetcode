class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int m = size(words),
            n = size(words.front()),
            k = size(s);
        vector<int> ans;
        unordered_map<string, int> freq;
        
        for (const string& word: words) {
            freq[word]++;
        }
        
        for (int i = 0; i <= k - m * n; i++) {
            int j = 0;
            unordered_map<string, int> seen;
            
            for (; j < m; j++) {
                string word = s.substr(i + j * n, n);
                seen[word]++;
                
                if (seen[word] > freq[word]) {
                    break;
                }
            }
            
            if (j == m) {
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};