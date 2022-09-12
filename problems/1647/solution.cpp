class Solution {
public:
    int minDeletions(string s) {
        int ans = 0;
        vector<int> freq(26);
        unordered_set<int> used;
        
        for (const char& ch: s) {
            freq[ch - 'a']++;
        }
        
        for (int i = 0; i < 26; i++) {
            for (; freq[i] > 0 and not used.insert(freq[i]).second; freq[i]--) {
                ans++;
            }
        }
        
        return ans;
    }
};