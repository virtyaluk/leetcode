class Solution {
public:
    int maxNumberOfBalloons(string text, string pattern = "balloon") {
        int ans = INT_MAX;
        unordered_map<char, int> freq, patFreq;
        
        for (const char& ch: text) {
            freq[ch]++;
        }
        
        for (const char& ch: pattern) {
            patFreq[ch]++;
        }
        
        for (auto [ch, fr]: patFreq) {
            ans = min(ans, freq[ch] / fr);
        }
        
        return ans;
    }
};