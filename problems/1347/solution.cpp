class Solution {
public:
    int minSteps(string s, string t) {
        int ans = 0;
        unordered_map<char, int> freq;
        
        for (const char& ch: s) {
            freq[ch]++;
        }
        
        for (const char& ch: t) {
            freq[ch]--;
        }
        
        for (auto [ignore, fr]: freq) {
            if (fr < 0) {
                ans += fr;
            }
        }
        
        return abs(ans);
    }
};