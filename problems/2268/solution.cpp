class Solution {
public:
    int minimumKeypresses(string s) {
        int ans = 0;
        vector<int> freq(26, 0);
        
        for (const char& ch: s) {
            freq[ch - 'a']++;
        }
        
        sort(begin(freq), end(freq), greater<>());
        
        for (int i = 0; i < 26; i++) {
            if (i < 9) {
                ans += freq[i];
            } else if (i < 18) {
                ans += 2 * freq[i];
            } else {
                ans += 3 * freq[i];
            }
        }
        
        return ans;
    }
};