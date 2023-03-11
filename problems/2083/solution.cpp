class Solution {
public:
    long long numberOfSubstrings(string s) {
        long long ans = 0;
        unordered_map<char, int> freq;
        
        for (const char& ch: s) {
            freq[ch]++;
            ans += freq[ch];
        }
        
        return ans;
    }
};