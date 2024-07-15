class Solution {
public:
    long long wonderfulSubstrings(string word) {
        long long mask = 0,
            ans = 0;
        vector<long long> freq(1024, 0);
        freq.front() = 1;
        
        for (const char& ch: word) {
            mask ^= 1 << (ch - 'a');
            ans += freq[mask];
            
            for (int i = 0; i < 10; i++) {
                ans += freq[mask ^ (1 << i)];
            }
            
            freq[mask]++;
        }
        
        return ans;
    }
};