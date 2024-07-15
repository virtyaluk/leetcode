class Solution {
public:
    int minSteps(string s, string t) {
        int ans = 0;
        vector<int> sc(26, 0),
            tc(26, 0);
        
        for (const char& ch: s) {
            sc[ch - 'a']++;
        }
        
        for (const char& ch: t) {
            tc[ch - 'a']++;
        }
        
        for (int i = 0; i < 26; i++) {
            ans += abs(sc[i] - tc[i]);
        }
        
        return ans;
    }
};