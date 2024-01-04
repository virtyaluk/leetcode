class Solution {
public:
    bool areOccurrencesEqual(string s) {
        unordered_map<char, int> um;
        
        for (const char& ch: s) {
            um[ch]++;
        }
        
        for (auto [ignore, cnt]: um) {
            if (cnt != size(s) / size(um)) {
                return false;
            }
        }
        
        return true;
    }
};