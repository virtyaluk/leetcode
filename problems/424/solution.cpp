class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans = 0, maxFreq = 0;
        unordered_map<char, int> freq;
        
        for (int left = 0, right = 0; right < size(s); right++) {
            maxFreq = max(maxFreq, ++freq[s[right]]);
            
            while (right - left + 1 - maxFreq > k) {
                freq[s[left++]]--;
            }
            
            ans = max(ans, right - left + 1);
        }
        
        return ans;
    }
};