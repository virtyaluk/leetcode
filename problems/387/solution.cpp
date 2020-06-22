class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> freq;
        
        for (const char& ch: s) {
            freq[ch]++;
        }
        
        for (int i = 0; i < size(s); i++) {
            if (freq[s[i]] == 1) {
                return i;
            }
        }
        
        return -1;
    }
};