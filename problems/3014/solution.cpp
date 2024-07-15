class Solution {
public:
    int minimumPushes(string word) {
        int ans = 0;
        vector<int> freq(26);
        
        for (const char& ch: word) {
            freq[ch - 'a']++;
        }
        
        sort(begin(freq), end(freq), greater<>());
        
        for (int i = 0; i < size(freq); i++) {
            if (not freq[i]) {
                continue;
            }
            
            ans += freq[i] * (i / 8 + 1);
        }
        
        return ans;
    }
};