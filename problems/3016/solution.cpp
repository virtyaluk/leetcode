class Solution {
public:
    int minimumPushes(string word) {
        int ans = 0;
        vector<int> freq(26, 0);
        
        for (const char& ch: word) {
            freq[ch - 'a']++;
        }
        
        sort(begin(freq), end(freq), greater<>());
        
        for (int i = 0, pushes = 1; i < 26; i++) {
            ans += freq[i] * pushes;
            
            if (i == 7 or i == 15 or i == 23) {
                pushes++;
            }
        }
        
        return ans;
    }
};